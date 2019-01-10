#include <sys/socket.h>
#include <unistd.h>
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"


void MyTestClientHandler::handleClient(int socketID) {
//    char buf[1024];
//    int numBytesRead;
//    numBytesRead = recv(socketID, buf, sizeof(buf), 0);
//    string ans = buf;
//    ans+="l\n";
//    size_t n;
//    n = write(socketID, ans.c_str(), ans.length());
//}
        string problem = "";
        string ans;
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
                           // FileCacheManager<string, string> strCM;
//                            if (strCM.isSolutionSaved(problem)) {
//                                //ans = cacheManager->popSolution(problem);
//                            } else {
//                                ans = solver->solve(problem);
//                                cacheManager->pushSolution(problem, ans);
//                            }
//                            //ans = ans + "\n";
                            ans = "dekel";
                            ssize_t n;

                            // Send message
                            n = write(socketID, ans.c_str(), ans.length());

                            if (n < 0) {
                                close(socketID);
                                return;
                            }


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



