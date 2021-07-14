# [Image Processing](../../)

## Intel Integrated Performance Primitives (Intel IPP) 

An exercise of digital image processing for Intel Integrated Performance Primitives (Intel IPP) function confirmation.  


## Content

* [Requirements](#requirements)
* [Programming](#programming)
* [Running](#running)

## Requirements

- Python
- OpenCV `apt install python-opencv`

## Programming

- Create `ipp.py`    

  ``` python
  import cv2

  print cv2.__version__               # ex. '3.4.0'
  print cv2.getBuildInformation()
  ```

## Running

- Result    

  ``` sh
  # python ipp.py
  
  General configuration for OpenCV 2.4.9.1 =====================================
    Version control:               unknown
  
    Platform:
      Host:                        Linux 3.13.0-85-generic x86_64
      CMake:                       3.5.1
      CMake generator:             Unix Makefiles
      CMake build tool:            /usr/bin/make
      Configuration:               Release
  
    C/C++:
      Built as dynamic libs?:      YES
      C++ Compiler:                /usr/bin/x86_64-linux-gnu-g++  (ver 5.3.1)
      C++ flags (Release):         -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2    -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -ffunction-sections -g -O2 -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG
      C++ flags (Debug):           -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2    -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -ffunction-sections -g  -O0 -DDEBUG -D_DEBUG
      C Compiler:                  /usr/bin/x86_64-linux-gnu-gcc
      C flags (Release):           -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2    -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wno-narrowing -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -ffunction-sections -g -O2 -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG
      C flags (Debug):             -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -Wdate-time -D_FORTIFY_SOURCE=2    -fsigned-char -W -Wall -Werror=return-type -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wmissing-prototypes -Wstrict-prototypes -Wundef -Winit-self -Wpointer-arith -Wshadow -Wno-narrowing -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -ffunction-sections -g  -O0 -DDEBUG -D_DEBUG
      Linker flags (Release):      -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-z,now -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-z,now
      Linker flags (Debug):        -Wl,-Bsymbolic-functions -Wl,-z,relro -Wl,-z,now
      Precompiled headers:         NO
  
    OpenCV modules:
      To be built:                 core flann imgproc highgui features2d calib3d ml objdetect video contrib legacy photo gpu java ocl python stitching superres ts videostab
      Disabled:                    world
      Disabled by dependency:      -
      Unavailable:                 androidcamera dynamicuda viz
  
    GUI:
      QT:                          NO
      GTK+ 2.x:                    YES (ver 2.24.30)
      GThread :                    YES (ver 2.48.0)
      GtkGlExt:                    YES (ver 1.2.0)
      OpenGL support:              YES (/usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libGL.so)
      VTK support:                 NO
  
    Media I/O:
      ZLib:                        /usr/lib/x86_64-linux-gnu/libz.so (ver 1.2.8)
      JPEG:                        /usr/lib/x86_64-linux-gnu/libjpeg.so (ver )
      PNG:                         /usr/lib/x86_64-linux-gnu/libpng.so (ver 1.2.54)
      TIFF:                        /usr/lib/x86_64-linux-gnu/libtiff.so (ver 42 - 4.0.6)
      JPEG 2000:                   /usr/lib/x86_64-linux-gnu/libjasper.so (ver 1.900.1)
      OpenEXR:                     /usr/lib/x86_64-linux-gnu/libImath.so /usr/lib/x86_64-linux-gnu/libIlmImf.so /usr/lib/x86_64-linux-gnu/libIex.so /usr/lib/x86_64-linux-gnu/libHalf.so /usr/lib/x86_64-linux-gnu/libIlmThread.so (ver 2.2.0)
  
    Video I/O:
      DC1394 1.x:                  NO
      DC1394 2.x:                  YES (ver 2.2.4)
      FFMPEG:                      YES
        codec:                     YES (ver 56.60.100)
        format:                    YES (ver 56.40.101)
        util:                      YES (ver 54.31.100)
        swscale:                   YES (ver 3.1.101)
        gentoo-style:              YES
      GStreamer:                   NO
      OpenNI:                      NO
      OpenNI PrimeSensor Modules:  NO
      PvAPI:                       NO
      GigEVisionSDK:               NO
      UniCap:                      NO
      UniCap ucil:                 NO
      V4L/V4L2:                    Using libv4l (ver 1.10.0)
      XIMEA:                       NO
      Xine:                        NO
  
    Other third-party libraries:
      Use IPP:                     NO
      Use Eigen:                   YES (ver 3.2.92)
      Use TBB:                     YES (ver 4.4 interface 9002)
      Use OpenMP:                  NO
      Use GCD                      NO
      Use Concurrency              NO
      Use C=:                      NO
      Use Cuda:                    NO
      Use OpenCL:                  YES
  
    OpenCL:
      Version:                     dynamic
      Use AMD FFT:                 NO
      Use AMD BLAS:                NO
  
    Python:
      Interpreter:                 /usr/bin/python2 (ver 2.7.11)
      Libraries:                   /usr/lib/x86_64-linux-gnu/libpython2.7.so (ver 2.7.11+)
      numpy:                       /usr/lib/python2.7/dist-packages/numpy/core/include (ver 1.11.0b3)
      packages path:               lib/python2.7/dist-packages
  
    Java:
      ant:                         /usr/bin/ant (ver 1.9.6)
      JNI:                         /usr/lib/jvm/default-java/include /usr/lib/jvm/default-java/include/linux /usr/lib/jvm/default-java/include
      Java tests:                  NO
  
    Documentation:
      Build Documentation:         YES
      Sphinx:                      /usr/bin/sphinx-build (ver (unknown version))
      PdfLaTeX compiler:           /usr/bin/pdflatex
  
    Tests and samples:
      Tests:                       NO
      Performance tests:           YES
      C/C++ Examples:              YES
  
    Install path:                  /usr
  
    cvconfig.h is in:              /build/opencv-SviWsf/opencv-2.4.9.1+dfsg/obj-x86_64-linux-gnu
  -----------------------------------------------------------------
  ```
