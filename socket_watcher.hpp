#ifndef NODE_MDNS_SOCKET_WATCHER_INCLUDED
#define NODE_MDNS_SOCKET_WATCHER_INCLUDED

#ifdef WIN32
# pragma warning( push )
# pragma warning( disable: 4251 )
#endif

#include <node.h>

#ifdef WIN32
# pragma warning( pop )
#endif

#ifndef NODE_VERSION_AT_LEAST
# include <node_version.h>
#endif

// XXX It would be better to test UV_VERSION_MAJOR and UV_VERSION_MINOR.
//     However, libuv didn't bump the version when uv_poll_t was introduced.
#if NODE_VERSION_AT_LEAST(0, 7, 9)
# define NODE_MDNS_USE_SOCKET_WATCHER
# warning Using SocketWatcher
#else
# warning Using IOWatcher
#endif

namespace node_pcap {

class SocketWatcher : public node::ObjectWrap {
    public:
        SocketWatcher();

        static void Initialize(v8::Handle<v8::Object> target);

    private:
        uv_poll_t* poll_;
        int fd_;
        int events_;

        static v8::Handle<v8::Value> New(const v8::Arguments & args);
        static v8::Handle<v8::Value> Set(const v8::Arguments & args);
        static v8::Handle<v8::Value> Start(const v8::Arguments& args);
        static v8::Handle<v8::Value> Stop(const v8::Arguments& args);
        
        void Start();
        void Stop();
        static void Callback(uv_poll_t *w, int status, int events);
};

} // end of namespace node_mdns

#endif // NODE_MDNS_SOCKET_WATCHER_INCLUDED
