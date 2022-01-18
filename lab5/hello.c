#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/ktime.h>
#include <linux/slab.h>

struct head_list {
struct head_list *next;
	ktime_t time;
};

static struct head_list *head;

MODULE_AUTHOR("Gubskoy Artur IO-92");
MODULE_DESCRIPTION("lab 5");
MODULE_LICENSE("Dual BSD/GPL");

static int param = 1;
module_param(param, uint, 0444);
MODULE_PARM_DESC(param, "Quantity of printed messages");

static int __init thisinit(void)
{
uint i;

struct head_list *var_1, *var_2;

head = kmalloc(sizeof(struct head_list *), GFP_KERNEL);

var_1 = head;
if (param == 0) {
	pr_warn("Param equals 0");
} else if (param >= 5 && param <= 10) {
	pr_warn("Param value between 5 and 10");
} else if (param > 10) {
	pr_warn("Param biger than 10");
return -EINVAL;
}

for (i = 0; i < param; i++) {
	var_1->next = kmalloc(sizeof(struct head_list), GFP_KERNEL);
	var_1->time = ktime_get();
	pr_info("Hello World!");
	var_2 = var_1;
	var_1 = var_1->next;
}

if (param != 0) {
	kfree(var_2->next);
	var_2->next = NULL;
}

pr_info("Param: %d\n", param);

return 0;
}

static void __exit thisexit(void)
{
struct head_list *var;

while (head != NULL && param != 0) {
	var = head;
	pr_info("Time: %lld", var->time);
	head = var->next;
	kfree(var);
}
pr_info("");
}

module_init(thisinit);
module_exit(thisexit);

