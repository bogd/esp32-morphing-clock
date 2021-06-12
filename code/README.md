# ESP32 Morphing Clock Shield Code

## Info

This is the code for my morphing clock project. See [the main Readme file](../) for features that are already implemented or still work-in-progress.

## Before You Start

This requires PlatformIO (and if you are not already using it, do yourself a favor and learn - I have waited way too long before moving to PlatformIO, and I truly regret not doing that sooner! :) ).

You will need some external components in order for all the features to work:
* The temperature/humidity display requires an external MQTT server, and a sensor pushing the data to that MQTT server
* OTA updates require a web server for serving the firmware, and an MQTT server for triggering the updates

Also, you will need to create your own versions of the creds_*.h files. I cannot share my versions (for obvious reasons :) ), but I did create some creds_*.h.sample files to show you what the contents should look like.