/************************else*************************************************
> File Name: dome.c
> Author: 夏椿林
> Mail: chunlin_xia@163.com 
> Created Time: 2020年08月24日 星期一 10时54分30秒
 ************************************************************************/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

#define NAME "mycdev"
//设置字符设备驱动的主设备号
int major = 0;

unsigned char back_light = 200;
module_param(back_light , byte ,0664);
MODULE_PARM_DESC(back_light,"this is back light rang,default:200");

int ww[10] = {0};
int num;
module_param_array(ww , int ,&num ,0664);
MODULE_PARM_DESC(ww,"this is back light rang,default:200");


//写fops结构体里面的open,read,write,close函数功能
int mycdev_open(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

ssize_t mycdev_read(struct file *filp, 
		char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

ssize_t mycdev_write(struct file *filp, 
				const char __user *ubuf, size_t size, loff_t *offs)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

int mycdev_close(struct inode *inode, struct file *filp)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

//初始化fops结构体
struct file_operations fops = {
	.open     = mycdev_open,
	.read     = mycdev_read,
	.write    = mycdev_write,
	.release = mycdev_close,
};

static int __init mycdev_init(void)
{
	//注册一个字符设备驱动
	major = register_chrdev(0,NAME,&fops);
	if(major <= 0){
		printk("register char device driver error\n");
		return major;
	}
	/////////////////////////////
	printk("hello drivers\n");
	printk("init back_light = %d\n",back_light);

	return 0;
}
static void __exit mycdev_exit(void)
{
	printk("exit drivers\n");
	printk("exit back_light = %d\n",back_light);
	//注销字符设备驱动
	unregister_chrdev(major,NAME);

}
module_init(mycdev_init);
module_exit(mycdev_exit);
MODULE_LICENSE("GPL");
