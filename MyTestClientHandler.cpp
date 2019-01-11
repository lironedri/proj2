#include <sys/socket.h>
#include <unistd.h>
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"


void server_side::MyTestClientHandler::handleClient(int socketID) {
        string problem = "";
        string ans = "";
        while (true) {
            char buf[1024];
            int numBytesRead = recv(socketID, buf, sizeof(buf), 0);

            if (numBytesRead > 0) {
                for (int i = 0; i < numBytesRead; i++) {
                    char c = buf[i];
                    if (c == '\n') {
                        if (problem.length() > 0) {
                            if (!problem.compare("end")) {
                                close(socketID);
                                return;
                            }
                            if (m_cacheManager->isSolutionSaved(problem)) {
                                ans = m_cacheManager->getSolution(problem);
                            } else {
                                ans = m_solver->solve(problem);
                                m_cacheManager->saveSolution(problem, ans);
                            }

                            ssize_t n;

                            // Send message
                            n = write(socketID, ans.c_str(), ans.length());

                            if (n < 0) {
                                close(socketID);
                                return;
                            }

                            ans = "";
                            problem = "";
                        }
                    } else problem += c;
                }
            } else {
                if (errno == EWOULDBLOCK) {
                    continue;
                }
                close(socketID);
                return;
            }
        }
    }



