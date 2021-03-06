#ifndef CAMERA_H_
#define CAMERA_H_

#include <stdbool.h>

typedef struct gui_activity_t gui_activity_t;
typedef struct gui_view_node_t gui_view_node_t;
typedef struct wait_event_data_t wait_event_data_t;

#define QR_MAX_STRING_LENGTH 256

typedef struct {
    // These indicate existing structures
    gui_activity_t* activity;
    gui_view_node_t* camera;
    gui_view_node_t* text;

    // Whether we have seen a qr code, and any string data extracted
    bool qr_seen;
    char strdata[QR_MAX_STRING_LENGTH];

    // These are 'owned' here and must be freed
    wait_event_data_t* event_data;
    void* image_buffer;
} jade_camera_data_t;

void cleanup_camera_data(jade_camera_data_t* camera_data);
void jade_camera_task(void* ignore);
void jade_camera_stop();

#endif /* CAMERA_H_ */
