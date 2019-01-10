//#ifndef PROJ2_MyParallelServer_H
//#define PROJ2_MyParallelServer_H
//
//#include <list>
//#include <vector>
//#include "ServerSide.h"
//#include "ClientHandler.h"
//using namespace std;
//
//using namespace server_side;
//namespace server_side {
//    class MyParallelServer : public Server {
//        vector<pthread_t> threadList;
//        bool shouldStop = false;
//    public:
//
//        void open(int port,ClientHandler *c);
//
//        void stop();
//
//        static void *thread_OpenDataServer(void *arg);
//
//    };
//
//    typedef struct {
//        int port;
//        ClientHandler *clientHandler;
//        bool *shouldStop;
//    } ServerStruct;
//}
//
//#endif //PROJ2_MyParallelServer_H
//
//
//
//
//
//
