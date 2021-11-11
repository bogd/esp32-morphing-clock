#ifndef CONFIG_H
#define CONFIG_H

//#define MQTT_USE_SSL 1
//#define USE_ANDROID_AP 1

// How often we refresh the time from the NTP server
#define NTP_REFRESH_INTERVAL_SEC 3600

// Timezone difference from GMT, expressed in seconds
#define TIMEZONE_DELTA_SEC 7200
// DST delta to apply
#define TIMEZONE_DST_SEC 3600

// How long are informational messages kept on screen
#define LOG_MESSAGE_PERSISTENCE_MSEC 30000

// How long do we consider the sensor data valid before declaring the sensor dead
#define SENSOR_DEAD_INTERVAL_SEC 600

//Button pin
#define BUTTON1_PIN 32

//Buzzer pin
#define BUZZER_PIN 2
#define BUZZER_PWM_CHANNEL 0
#define BUZZER_PWM_RESOLUTION 8

// Screen positioning settings
// Panel size
#define PANEL_WIDTH 128
#define PANEL_HEIGHT 64

// Clock
#define CLOCK_X 3
#define CLOCK_Y 21
#define CLOCK_SEGMENT_HEIGHT 8
#define CLOCK_SEGMENT_WIDTH 8
#define CLOCK_SEGMENT_SPACING 5
#define CLOCK_WIDTH 6*(CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING)+4
#define CLOCK_HEIGHT 2*CLOCK_SEGMENT_HEIGHT+3
//color565 == ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3)
#define CLOCK_DIGIT_COLOR  ((0x00 & 0xF8) << 8) | ((0xFF & 0xFC) << 3) | (0xFF >> 3)
//Delay in ms for clock animation - should be below 30ms for a segment size of 8
#define CLOCK_ANIMATION_DELAY_MSEC 20

// Day of week
#define DOW_X 90
#define DOW_Y 21
#define DOW_COLOR ((0x00 & 0xF8) << 8) | ((0x40 & 0xFC) << 3) | (0xFF >> 3)
// Date
#define DATE_X DOW_X
#define DATE_Y DOW_Y+11
#define DATE_COLOR DOW_COLOR
//Width and height are for both DATE and DOW
#define DATE_WIDTH 40
#define DATE_HEIGHT 18


// Weather sensor data
#define SENSOR_DATA_X 0
#define SENSOR_DATA_Y 0
#define SENSOR_DATA_WIDTH 128
#define SENSOR_DATA_HEIGHT 8
#define SENSOR_DATA_COLOR ((0x00 & 0xF8) << 8) | ((0x8F & 0xFC) << 3) | (0x00 >> 3)
#define SENSOR_ERROR_DATA_COLOR ((0xFF & 0xF8) << 8) | ((0x00 & 0xFC) << 3) | (0x00 >> 3)

// Light sensor data
#define LIGHT_DATA_X 0
#define LIGHT_DATA_Y 9
#define LIGHT_DATA_WIDTH 44
#define LIGHT_DATA_HEIGHT 8
#define LIGHT_DATA_COLOR ((0x00 & 0xF8) << 8) | ((0xFF & 0xFC) << 3) | (0x00 >> 3)
//Maximum lux value that will be accepted as valid (sometimes the sensor will return erroneous values)
#define LIGHT_THRESHOLD 9999
#define LIGHT_READ_INTERVAL_SEC 10

// Log messages at the bottom
#define LOG_MESSAGE_COLOR ((0xFF & 0xF8) << 8) | ((0x00 & 0xFC) << 3) | (0x00 >> 3)

#define BITMAP_X 0
#define BITMAP_Y 44

#define HEARTBEAT_X 120
#define HEARTBEAT_Y 21

// Watchdog settings
#define WDT_TIMEOUT 60   // If the WDT is not reset within X seconds, reboot the unit
        // Do NOT set this too low, or the WDT will prevent OTA updates from completing!!

// Weather - today, and 5-day forecast
#define WEATHER_TODAY_X 56
#define WEATHER_TODAY_Y 1

#define WEATHER_FORECAST_X 90
#define WEATHER_FORECAST_Y 44

//Temperature range for today
#define TEMPRANGE_X 0
#define TEMPRANGE_Y 44
#define TEMPRANGE_WIDTH 64
#define TEMPRANGE_HEIGHT 8
#define TEMPRANGE_COLOR ((0x00 & 0xF8) << 8) | ((0xFF & 0xFC) << 3) | (0xFF >> 3)

// How often to refresh weather forecast data
// (limited by API throttling)
#define WEATHER_REFRESH_INTERVAL_SEC 14400

#endif
