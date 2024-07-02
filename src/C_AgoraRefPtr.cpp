// 引入AgoraRTM SDK
#include "AgoraRefPtr.h"

using namespace agora;

// Agora C封装
#include "C_AgoraRefPtr.h"

#pragma region agora

#pragma region C_RefCountInterface

//   void C_RefCountInterface_AddRef();
//   enum C_RefCountReleaseStatus C_RefCountInterface_Release();
//   void C_RefCountInterface_HasOneRef();

#pragma endregion C_RefCountInterface

#pragma region C_agora_refptr

// C_agora_refptr *C_agora_refptr_New()
// {
//     return (C_agora_refptr *)(new agora_refptr<>());
// }

// C_agora_refptr C_agora_refptr_New_p(void *p)
// {
// }

// void C_agora_refptr_Delete(C_agora_refptr *refptr)
// {
// }

// void *C_agora_refptr_get(C_agora_refptr *refptr)
// {
// }

#pragma endregion C_agora_refptr

#pragma endregion agora
