
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("vlc_source_code")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.

add_compile_definitions(HAVE_ATTRIBUTE_PACKED # for vlc_codecs.h
        # for avcommon.h
        HAVE_CONFIG_H
        HAVE_LIBAVUTIL_AVUTIL_H
        HAVE_LIBAVFORMAT_AVFORMAT_H
        HAVE_LIBAVCODEC_AVCODEC_H
        # for modules
        __PLUGIN__
        MODULE_NAME="vlc_module_name"
        MODULE_STRING="vlc_module_string"
        # Android related
        __ANDROID__
        ANDROID_API=21)

file(GLOB_RECURSE MODULE_SRCS
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/config.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/lib*/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/lib*/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/fftools/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/tools/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg/doc/examples/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ebml/src/*.cpp"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/lib/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/lib/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/lib/*/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/lib/*/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/src/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/src/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/freetype/src/*/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/freetype/src/*/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/fribidi/lib/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/fribidi/lib/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/harfbuzz/src/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/harfbuzz/src/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/harfbuzz/src/*.hh"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/harfbuzz/src/*.cc"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libass/libass/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libass/libass/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/descriptors/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/descriptors/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/tables/*.h"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libdvbpsi/src/tables/*.c"
        "../../../../vlc/build-android-aarch64-linux-android/*.h"
        "../../../../vlc/build-android-aarch64-linux-android/src/*.h"
        "../../../../vlc/build-android-aarch64-linux-android/ndk/*.c"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libass/config.h"
        "../../../../vlc/src/*.h"
        "../../../../vlc/src/*.c"
        "../../../../vlc/src/*/*.h"
        "../../../../vlc/src/*/*.c"
        "../../../../vlc/lib/*.c"
        "../../../../vlc/lib/*.h"
        "../../../../vlc/modules/*/*.c"
        "../../../../vlc/modules/*/*.h"
        "../../../../vlc/modules/*/*/*.c"
        "../../../../vlc/modules/*/*/*.cpp"
        "../../../../vlc/modules/*/*/*.h"
        "../../../../vlc/modules/*/*/*/*.c"
        "../../../../vlc/modules/*/*/*/*.h"
        "../../../../vlc/modules/*/*/*/*.cpp"
        "../../../../vlc/modules/*/*/*/*.hpp"
        "../../../../vlc/compat/*.c"
        "../../../../vlc/test/src/*/*.h"
        "../../../../vlc/test/src/*/*.c"
        "../../../../libvlc/jni/*.c")

include_directories("../../../../vlc/include"
        "../../../../vlc/src"
        "../../../../vlc/modules/codec"
        "../../../../vlc/modules/codec/omxil"
        "../../../../vlc/modules/demux/adaptive"
        "../../../../vlc/contrib/aarch64-linux-android/include"
        "../../../../vlc/contrib/aarch64-linux-android/include/opus"
        "../../../../vlc/contrib/aarch64-linux-android/include/fribidi"
        "../../../../vlc/contrib/aarch64-linux-android/include/harfbuzz"
        "../../../../vlc/build-android-aarch64-linux-android" # config.h
        "../../../../vlc/build-android-aarch64-linux-android/include"
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ffmpeg" # config.h
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/ebml" # mkv
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/gnutls/lib" # gnutls
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/freetype/include" # freetype
        "../../../../vlc/contrib/contrib-android-aarch64-linux-android/libass" # libass
)

add_library(${CMAKE_PROJECT_NAME} SHARED
    # List C/C++ source files with relative paths to this CMakeLists.txt.
    vlc_source_code.cpp
        ${INCS}
        ${MODULE_SRCS})

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
    # List libraries link to the target library
    android
    log)
