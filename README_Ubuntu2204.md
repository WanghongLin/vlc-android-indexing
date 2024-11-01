# vlc-android build requisites in Ubuntu 22.04

### ndk r21

### prepare toolchains
```shell
cd $ANDROID_NDK/toolchains/llvm/prebuilt/linux-x86_64/bin
ln -s aarch64-linux-android30-clang aarch64-linux-android-gcc
ln -s aarch64-linux-android30-clang++ aarch64-linux-android-g++
```

### install `gettext`
```shell
$ apt install gettext
```

### use java version 17
