#ifndef _CONFIG_GPIO_H
#define _CONFIG_GPIO_H

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>
#include <stdio.h>
#include "config_macros.h"

extern volatile int dcToggleFlag1; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag2; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag3; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag4; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag5; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag6; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag7; /* Flag to signal a BUT1 press */
extern volatile int dcToggleFlag8; /* Flag to signal a BUT1 press */

void but1press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but2press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but3press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but4press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but5press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but6press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but7press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
void but8press_cbfunction(const struct device *dev, struct gpio_callback *cb, uint32_t pins);

void get_bind(void);

#endif
