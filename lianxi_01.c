// 头文件
#include <gtk/gtk.h>
void haha(GtkButton * button,gpointer user_data)
{
	const gchar * text = gtk_button_get_label(button);
	printf("%s\n",text);
}
//++++++++++++++++++++++++++++++++++++++

// 定义主函数，没有const
int main(int argc, char *argv[])
{
	// 初始化,第一句，写一次
	gtk_init(&argc,&argv);
	// 创建窗口
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// 控件     指针 变量名 gtk  窗口      新建       有边框
	
    // 设置窗口属性
    // 标题
    gtk_window_set_title(GTK_WINDOW(window),"我是标题");
    // 大小
    gtk_widget_set_size_request(window,600,600);
    // 布局
    GtkWidget * hbox = gtk_hbox_new(TRUE,10);
    gtk_container_add(GTK_CONTAINER(window),hbox);


 	// 创建按钮
 	GtkWidget * button01 = gtk_button_new_with_label("可以对我发泄");
 	// 把按钮放窗口
 	gtk_container_add(GTK_CONTAINER(hbox),button01);

 	// 信号
 	g_signal_connect(button01,"pressed",G_CALLBACK(haha),NULL);

 	
 	GtkWidget * button02 = gtk_button_new_with_label("可以点我");
 	gtk_container_add(GTK_CONTAINER(hbox),button02);
 	g_signal_connect(button02,"pressed",G_CALLBACK(haha),NULL);

 	
 	GtkWidget * button03 = gtk_button_new_with_label("别发火，点我消消气");
 	gtk_container_add(GTK_CONTAINER(hbox),button03);
 	g_signal_connect(button03,"pressed",G_CALLBACK(haha),NULL);

	// 点X程序退出
	g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

	// 显示窗口
	gtk_widget_show_all(window);

	//gtk  控件  显示  变量名
	// 主事件循环
    gtk_main();
	return 0;
}
