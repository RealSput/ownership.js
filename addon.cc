#include <node_api.h>

napi_value get_value_wrapper(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc = 1;
  napi_value argv[1];
  napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  if (argc != 1) {
    napi_throw_type_error(env, nullptr, "Invalid number of arguments");
    return nullptr;
  }

  void* data = nullptr;
  status = napi_get_value_external(env, argv[0], &data);
  if (status != napi_ok) {
    napi_throw_type_error(env, nullptr, "Invalid argument");
    return nullptr;
  }

  Owner* owner = static_cast<Owner*>(data);
  int64_t value = get_value(env, owner);

  napi_value result;
  status = napi_create_int64(env, value, &result);
  if (status != napi_ok) {
    napi_throw_type_error(env, nullptr, "Failed to create int64");
    return nullptr;
  }

  return result;
}
