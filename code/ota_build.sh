#!/bin/bash

. creds_ota.sh

pio run

if [ $? -ne 0 ]
then
  echo "Build finished with error!"
  exit 1
fi

cp .pio/build/esp32dev/firmware.bin /tmp/$MQTT_ESP_HOSTNAME.bin

echo "Starting container..."

CONTAINER_ID=$(docker container run -d -p 8080:80 --rm -v /tmp/$MQTT_ESP_HOSTNAME.bin:/usr/share/nginx/html/$MQTT_ESP_HOSTNAME.bin nginx:latest)

echo "Sending MQTT OTA request"

mosquitto_pub -h $MQTT_HOST -u $MQTT_USER -P $MQTT_PASS -t $MQTT_TOPIC -m $MQTT_PAYLOAD

echo "Waiting for OTA"
sleep $WAIT_TIME_SEC

echo "Done - stopping container!"
docker stop $CONTAINER_ID


