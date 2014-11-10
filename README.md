omnis.xcomp.example
===================

Example xcomp made with omnis.xcomp.framework

Directories are setup relative and assume the framework is installed within the Omnis SDK folders:
- Omnis SDK
 - complib
 - omnis.xcomp.framework
 - omnis.xcomp.example
 - ...

Compiling under Mac OS X
========================
Our project files for Mac OS X have now been updated so this project compiles using XCode 6
Note that the default XCode installation comes only with the SDK for 10.9 and upwards while combining XCOMPs for Omnis requires SDK 10.6 to be available. 
You will need to copy the 10.6 SDK from an XCode 4 installation into:
Applications:Xcode.app:Contents:Developer:Platforms:MacOSX.platform:Developer:SDKs
After that you can compile this XComp.
