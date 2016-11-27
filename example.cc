#include <nan.h>

const int maxValue = 10;
int numberOfCalls = 0;

void WhoAmI(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  auto message = Nan::New<v8::String>("I'm a Node Hero!").ToLocalChecked();
  args.GetReturnValue().Set(message);
}

void Increment(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  if (!args[0]->IsNumber()) {
    Nan::ThrowError("Argument must be a number");
    return;
  }

  double argsValue = args[0]->NumberValue();
  if (numberOfCalls + argsValue > maxValue) {
    Nan::ThrowError("Over the roof!");
    return;
  }

  numberOfCalls += argsValue;

  auto currentNumberOfCalls =
    Nan::New<v8::Number>(numberOfCalls);

  args.GetReturnValue().Set(currentNumberOfCalls);
}

void Initialize(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("whoami").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(WhoAmI)->GetFunction());
  exports->Set(Nan::New("increment").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(Increment)->GetFunction());
}

NODE_MODULE(addon, Initialize)
