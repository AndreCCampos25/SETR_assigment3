#include "config_gpio.h"

static struct gpio_callback but1_cb_data; /* Callback structure */
static struct gpio_callback but2_cb_data; /* Callback structure */
static struct gpio_callback but3_cb_data; /* Callback structure */
static struct gpio_callback but4_cb_data; /* Callback structure */
static struct gpio_callback but5_cb_data; /* Callback structure */
static struct gpio_callback but6_cb_data; /* Callback structure */
static struct gpio_callback but7_cb_data; /* Callback structure */
static struct gpio_callback but8_cb_data; /* Callback structure */

volatile int dcToggleFlag1 = 0;
volatile int dcToggleFlag2 = 0;
volatile int dcToggleFlag3 = 0;
volatile int dcToggleFlag4 = 0;
volatile int dcToggleFlag5 = 0;
volatile int dcToggleFlag6 = 0;
volatile int dcToggleFlag7 = 0;
volatile int dcToggleFlag8 = 0;

void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag1 = 1;
}

void but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag2 = 1;
}

void but3press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag3 = 1;
}

void but4press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag4 = 1;
}


void but5press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{ 
  dcToggleFlag5 = 1;
}

void but6press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag6 = 1;
}

void but7press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag7 = 1;
}

void but8press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
  dcToggleFlag8 = 1;
}


void get_bind(void)
{
  
  const struct device *gpio0_dev;       
  int ret=0;                             
    
  gpio0_dev = device_get_binding(DT_LABEL(GPIO0_NID));
  if (gpio0_dev == NULL)
  {
    printk("Error: Failed to bind to GPIO0\n\r");        
    return;
  }
  else
      printk("Bind to GPIO0 successfull \n\r");        

//#################################################################################################    
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT1, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 1 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT1, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT1 pin \n\r", ret);
    return;
  }

  gpio_init_callback(&but1_cb_data, but1press_cbfunction, BIT(BOARDBUT1));
  gpio_add_callback(gpio0_dev, &but1_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT2, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 2 \n\r", ret);
    return;
  }
  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT2, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT2 pin \n\r", ret);
    return;
  }

  gpio_init_callback(&but2_cb_data, but2press_cbfunction, BIT(BOARDBUT2));
  gpio_add_callback(gpio0_dev, &but2_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT3, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 3 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT3, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT3 pin \n\r", ret);
    return;
  }

  gpio_init_callback(&but3_cb_data, but3press_cbfunction, BIT(BOARDBUT3));
  gpio_add_callback(gpio0_dev, &but3_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT4, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 4 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT4, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT4 pin \n\r", ret);
    return;
  }

  gpio_init_callback(&but4_cb_data, but4press_cbfunction, BIT(BOARDBUT4));
  gpio_add_callback(gpio0_dev, &but4_cb_data);
//#################################################################################################    

  ret = gpio_pin_configure(gpio0_dev, BOARDBUT5, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 5 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT5, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT5 pin \n\r", ret);
    return;
  }
    
  gpio_init_callback(&but5_cb_data, but5press_cbfunction, BIT(BOARDBUT5));
  gpio_add_callback(gpio0_dev, &but5_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT6, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 6 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT6, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT6 pin \n\r", ret);
    return;
  }

  gpio_init_callback(&but6_cb_data, but6press_cbfunction, BIT(BOARDBUT6));
  gpio_add_callback(gpio0_dev, &but6_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT7, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 7 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT7, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT7 pin \n\r", ret);
    return;
  }
  
  gpio_init_callback(&but7_cb_data, but7press_cbfunction, BIT(BOARDBUT7));
  gpio_add_callback(gpio0_dev, &but7_cb_data);
//#################################################################################################
  ret = gpio_pin_configure(gpio0_dev, BOARDBUT8, GPIO_INPUT | GPIO_PULL_UP);
  if (ret < 0) {
    printk("Error %d: Failed to configure BUT 8 \n\r", ret);
    return;
  }

  ret = gpio_pin_interrupt_configure(gpio0_dev, BOARDBUT8, GPIO_INT_EDGE_TO_ACTIVE);
  if (ret != 0) {
    printk("Error %d: failed to configure interrupt on BUT8 pin \n\r", ret);
    return;
  }
  
  gpio_init_callback(&but8_cb_data, but8press_cbfunction, BIT(BOARDBUT8));
  gpio_add_callback(gpio0_dev, &but8_cb_data);
//#################################################################################################      

}   