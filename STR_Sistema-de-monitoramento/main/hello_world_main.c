#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/random.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"

//Função toque
#include "esp_log.h"
#include "driver/touch_pad.h"

#define ESTAVEL 1
#define INSTAVEL 0
#define TOUCH_THRESH_NO_USE   (0)
#define TOUCHPAD_FILTER_TOUCH_PERIOD (10)
#define TOUCH_PAD_MAX 4
#define BLINK_GPIO 2

static const char* TAG = "Touch pad";
int sensor_duto_1= ESTAVEL,sensor_duto_2= ESTAVEL,sensor_duto_3= ESTAVEL;
int sensor_poco_1 = ESTAVEL,sensor_poco_2 = ESTAVEL,sensor_poco_3 = ESTAVEL;
volatile uint16_t isrMask=0;

SemaphoreHandle_t mutual_exclusion_mutex;

void display(){
    if(sensor_duto_1 ==0){
        printf("\n\n\nSensor do DUTO 1 INSTAVEL");
        printf("\nContra medida APLICADA");
        printf("\nPOCO ESTAVEL 1");
    }
    else if(sensor_poco_1==0){
        printf("\n\n\nSensor do POCO INSTAVEL");
        printf("\nPOCO 1 DESLIGDO");
         printf("\nDUTO 1 INATIVO");
    }
    else{
        printf("\n\nSensor do DUTO 1 ESTAVEL");
        printf("\nSensor do POCO 1 ESTAVEL");
    } 
    if(sensor_duto_2 ==0){
        printf("\n\n\nSensor do DUTO 2 INSTAVEL");
        printf("\nContra medida APLICADA");
        printf("\nPOCO ESTAVEL 2");
    }
    else if(sensor_poco_2==0){
        printf("\n\n\nSensor do POCO 2 INSTAVEL");
        printf("\nPOCO 2 DESLIGDO");
         printf("\nDUTO 2 INATIVO");
    }
    else{
        printf("\n\nSensor do DUTO 2 ESTAVEL");
        printf("\nSensor do POCO 2 ESTAVEL");
    } 
    if(sensor_duto_3 ==0){
        printf("\n\n\nSensor do DUTO 3 INSTAVEL");
        printf("\nContra medida APLICADA");
        printf("\nPOCO ESTAVEL 3");
    }
    else if(sensor_poco_3==0){
        printf("\n\n\nSensor do POCO 3 INSTAVEL");
        printf("\nPOCO 3 DESLIGDO");
         printf("\nDUTO 3 INATIVO");
    }
    else{
        printf("\n\nSensor do DUTO 3 ESTAVEL");
        printf("\nSensor do POCO 3 ESTAVEL");
    } 
} 

static void tp_read_task(void *pvParameter)
{
     gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
            //interrupt mode, enable touch interrupt
            touch_pad_intr_enable();

            xSemaphoreTake(mutual_exclusion_mutex, portMAX_DELAY);
			if (isrMask==0x1){
            	//ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_duto_1 = INSTAVEL;
                  // Blink on (output high) 
                gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(200 / portTICK_RATE_MS);
            }
            else if(isrMask == 0x10){
               // ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_poco_1 = INSTAVEL;
                  // Blink on (output high) 
                 gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(300 / portTICK_RATE_MS);
            }
            else{
                sensor_duto_1 = ESTAVEL;
                sensor_poco_1 = ESTAVEL;
                gpio_set_level(BLINK_GPIO, 0);
                //vTaskDelay(1000 / portTICK_RATE_MS);
            }

            if (isrMask == 0x40){
            	//ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_duto_2 = INSTAVEL;
                  // Blink on (output high) 
                gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(200 / portTICK_RATE_MS);
            }
            else if(isrMask == 0x80){
               // ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_poco_2 = INSTAVEL;
                  // Blink on (output high) 
                 gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(300 / portTICK_RATE_MS);
            }
            else{
                sensor_duto_2 = ESTAVEL;
                sensor_poco_2 = ESTAVEL;
                gpio_set_level(BLINK_GPIO, 0);
                //vTaskDelay(1000 / portTICK_RATE_MS);
            }

            if (isrMask == 0x100){
            	//ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_duto_3 = INSTAVEL;
                  // Blink on (output high) 
                gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(200 / portTICK_RATE_MS);
            }
            else if(isrMask==0x200){
               // ESP_LOGI(TAG, "Bit mask from ISR: %#x",isrMask );
                sensor_poco_3 = INSTAVEL;
                  // Blink on (output high) 
                 gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(300 / portTICK_RATE_MS);
            }
            else{
                sensor_duto_3 = ESTAVEL;
                sensor_poco_3 = ESTAVEL;
                gpio_set_level(BLINK_GPIO, 0);
                //vTaskDelay(1000 / portTICK_RATE_MS);
            }
            xSemaphoreGive(mutual_exclusion_mutex);
		isrMask=0;

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
/* Handle an interrupt triggered when a pad is touched.
  Recognize what pad has been touched and save it in a table.*/
static void tp_rtc_intr(void * arg)
{
    isrMask = touch_pad_get_status();
    //clear interrupt
    touch_pad_clear_status();

}

//==================================================================================================
// POÇO 1
void thread_duto_gas_1(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }
}
void thread_duto_oleo_1(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }

}
void thread_poco_1(void *pvParameter){
    while(1){
		vTaskDelay(75 / portTICK_RATE_MS);
    }
}
//===============================================================================================
// POÇO 2
void thread_duto_gas_2(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }
}
void thread_duto_oleo_2(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }

}
void thread_poco_2(void *pvParameter){
    while(1){
		vTaskDelay(75 / portTICK_RATE_MS);
    }
}

//================================================================================================
// POÇO 3
void thread_duto_gas_3(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }
}
void thread_duto_oleo_3(void *pvParameter){

    while(1){
		vTaskDelay(38 / portTICK_RATE_MS);
    }

}
void thread_poco_3(void *pvParameter){
    while(1){
		vTaskDelay(75 / portTICK_RATE_MS);
    }
}

void app_main(){

//CONFIGURAÇÕES DA FUNÇÃO TOQUE
//=============================================================================================
  // Initialize touch pad peripheral, it will start a timer to run a filter
    ESP_LOGI(TAG, "Initializing touch pad");

    // Register touch interrupt ISR
    touch_pad_init();//INICIALIZA FUNÇÃO
    touch_pad_set_fsm_mode(TOUCH_FSM_MODE_TIMER);
    touch_pad_config(TOUCH_PAD_NUM0, 500);//MAPEIA PINO D4  = 0x1 
    touch_pad_config(TOUCH_PAD_NUM4, 500);//MAPEIA PINO D13 = 0x10
    touch_pad_config(TOUCH_PAD_NUM6, 500);//MAPEIA PINO D14 = 0x40 
    touch_pad_config(TOUCH_PAD_NUM7, 500);//MAPEIA PINO D27 = 0x80
    touch_pad_config(TOUCH_PAD_NUM8, 500);//MAPEIA PINO D33 = 0x100 
    touch_pad_config(TOUCH_PAD_NUM9, 500);//MAPEIA PINO D32 = 0x200
    
    touch_pad_isr_register(tp_rtc_intr, NULL);//REGISTRA TOUCH PAD
    //touch_pad_intr_enable();
    // Start a task to show what pads have been touched
//===============================================================================================

// TRECHO CODIGO MONITORAMENTO
//===============================================================================================
	nvs_flash_init();
    mutual_exclusion_mutex = xSemaphoreCreateMutex();
	
    printf("\nSistemas de Monitoramento");
	
	 if( mutual_exclusion_mutex != NULL ){
       // The semaphore was created successfully.
       // The semaphore can now be used.
       printf("Mutex was created\n");
	   }
    //TOUCH PAD
	xTaskCreatePinnedToCore(&tp_read_task,     "touch_pad_read_task", 3072, NULL, 5, NULL, 0);

    //POÇO 1
    xTaskCreatePinnedToCore(&thread_poco_1,      "Th_poco 1"          , 3072, NULL, 3, NULL, 0);
    xTaskCreatePinnedToCore(&thread_duto_oleo_1, "Th_Oleo 1"          , 3072, NULL, 1, NULL, 1);
	xTaskCreatePinnedToCore(&thread_duto_gas_1,  "Th_Gas  1"          , 3072, NULL, 1, NULL, 1);
    
    //POÇO 2
    xTaskCreatePinnedToCore(&thread_poco_2,      "Th_poco 2"          , 3072, NULL, 3, NULL, 0);
    xTaskCreatePinnedToCore(&thread_duto_oleo_2, "Th_Oleo 2"          , 3072, NULL, 1, NULL, 1);
	xTaskCreatePinnedToCore(&thread_duto_gas_2,  "Th_Gas  2"          , 3072, NULL, 1, NULL, 1);

    //POÇO 3
    xTaskCreatePinnedToCore(&thread_poco_3,      "Th_poco 3"          , 3072, NULL, 3, NULL, 0);
    xTaskCreatePinnedToCore(&thread_duto_oleo_3, "Th_Oleo 3"          , 3072, NULL, 1, NULL, 1);
	xTaskCreatePinnedToCore(&thread_duto_gas_3,  "Th_Gas  3"          , 3072, NULL, 1, NULL, 1);

    while(1){
        display();
	    vTaskDelay(1000 / portTICK_RATE_MS);
	}
  //================================================================================================
}