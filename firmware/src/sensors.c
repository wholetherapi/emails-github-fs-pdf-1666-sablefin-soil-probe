#include "sensors.h"
#include "sht45.h"
#include "tdr.h"

void sensors_init(void) {
    sht45_configure(SHT45_REP_HIGH);
    tdr_calibrate(TDR_PROFILE_LOAM);
}

void sensors_read(sensor_sample_t *out) {
    out->soil_moisture = tdr_read_percent();
    out->soil_temp_c = tdr_read_temperature();
    out->air_temp_c = sht45_read_temperature();
    out->air_humidity = sht45_read_humidity();
}
