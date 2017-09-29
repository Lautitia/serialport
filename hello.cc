#include <node.h>
#include <v8.h>

using namespace v8;
using namespace node;

void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    HandleScope scope(isolate);
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello world"));
}

void init(v8::Local<v8::Object> target) {
    NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(hello, init)