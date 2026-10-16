# How to make your own firmware?

### On Linux:

#### Warning!

All next actions must be done in case-sensitive filesystem, that supports symbolic links!

#### 1. Download official firmware file

You can find firmware file links on Z-CAM official web-site or on this page (watch "Original Firmwares" section above).

#### 2. Unpack firmware file as ZIP-archive

`mkdir update`

`unzip update.zip -d update`

`rm update.zip`

`cd update`

#### 3. Decrypt update_data.bin file to update_data.zip

Use my **update_data_crypter** tool to decrypt `update_data.zip` for your firmware version.

Example:

`/<path_to_crypter>/crypter -d -v0.93 -i update_data.bin -o update_data.zip`

#### 4. Unpack update_data.zip using password you can find above

Don't forget to use escaping for special characters. For example, password `gmi!!emoclew` must be converted to `gmi\!\!emoclew` in terminal.

`mkdir update_data`

`unzip -P <place_password_here> update_data.zip -d update_data`

`rm update_data.zip`

`cd update_data`

#### 5. Unpack RootFS

`mkdir rootfs`

`tar -xzf rootfs.tar.gz -C rootfs`

`rm rootfs.tar.gz`

#### 6. Make any changes in unpacked RootFS you want

You know what to do here :)

#### 7. Pack RootFS

`cd rootfs`

`tar -czvf ./../rootfs.tar.gz *`

`cd ..`

`rm -rf rootfs`

#### 8. Pack update_data.zip

`zip -P <place_password_here> -0 -r ../update_data.zip *`

`cd ..`

`rm -rf update_data`

#### 9. Encrypt update_data.zip file to update_data.bin

Use my **update_data_crypter** tool to encrypt `update_data.zip` for your firmware version. Important: DO NOT use old name `update_data.bin` because this file is needed for signature checking.

Example:

`/<path_to_crypter>/crypter -e -v0.93 -i update_data.zip -o update_data_new.bin`

`rm update_data.zip`

#### 10. Patch install_binary executable file to bypass signature checking

A bit complicated to explain here.

#### 11. Recalculate MD5 for all files, listed in md5.txt

`md5sum version.txt update_data.bin install_binary update.script > md5.txt`

#### 12. Pack firmware to normal deflate-compressed ZIP

`zip -r ../update.zip *`

`cd ..`

`rm -rf update`

**Ready! Now you can flash your firmware to your camera and test it!**
