
#include "iostream"
#include "SSTDumpTool.h"
#include "rocksdb/options.h"
#include "rocksdb/sst_dump_tool.h"
#include "cplusplus_to_java_convert.h"
#include "string"

jlong Java_SSTDumpTool_newSSTDumpTool(JNIEnv *env, jclass jclass1) {
//    ROCKSDB_NAMESPACE::SSTDumpTool* sstDumpTool = new ROCKSDB_NAMESPACE::SSTDumpTool();
//    return GET_CPLUSPLUS_POINTER(sstDumpTool);
    return 0;
}

void Java_SSTDumpTool_runInternal(JNIEnv *env, jobject obj, jlong sst_dump_tool_native_handle, jobjectArray argsArray,
                                  jlong options_native_handle) {
    auto* options = reinterpret_cast<const ROCKSDB_NAMESPACE::Options*>(options_native_handle);
    ROCKSDB_NAMESPACE::SSTDumpTool dumpTool;
    int length = env->GetArrayLength(argsArray);
    char* args[length + 1];
    args[0] = strdup("./sst_dump");
    std::cout<<length<<std::endl;
    for(int i = 0; i < env->GetArrayLength(argsArray); i++) {

        args[i+1] = (char*)env->GetStringUTFChars((jstring)env->
                GetObjectArrayElement(argsArray, (jsize)i), JNI_FALSE);
        std::cout<<args[i+1]<<std::endl;
    }
    dumpTool.Run(length + 1, args, *options);
}

void Java_SSTDumpTool_disposeInternal(JNIEnv *env, jobject, jlong) {
    std::cout<<"Java_SSTDumpTool_disposeInternal"<<std::endl;
}
