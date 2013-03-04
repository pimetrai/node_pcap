#include <v8.h>
#include <node.h>

#define NODE_MDNS_USE_SOCKET_WATCHER

#ifdef NODE_MDNS_USE_SOCKET_WATCHER
#include "socket_watcher.hpp"
#endif

using namespace v8;
using namespace node;

namespace node_pcap {


// === additions ========================================
Handle<Value> exportConstants(Arguments const& args);

// === locals ===========================================
void defineFunction(Handle<Object> target, const char * name, InvocationCallback f);

void
init(Handle<Object> target) {
    HandleScope scope;

#ifdef NODE_MDNS_USE_SOCKET_WATCHER
    SocketWatcher::Initialize( target );
#endif

}

inline
void
defineFunction(Handle<Object> target, const char * name, InvocationCallback f) {
    target->Set(String::NewSymbol(name),
            FunctionTemplate::New(f)->GetFunction());
}



} // end of namespace node_mdns

NODE_MODULE(socket_watcher_binding,node_pcap::init);
