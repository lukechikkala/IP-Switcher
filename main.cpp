#include <gtkmm.h>
#include <iostream>

void on_button_1_click();
void on_button_2_click();

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "example.com");

	Gtk::Window window;
	Gtk::Button button_1("Static");
	Gtk::Button button_2("DHCP");
	Gtk::Grid grid;
	Gtk::Frame frame;

	window.set_title("IP Switcher");
	window.set_default_size(500,250);
	window.set_position(Gtk::WIN_POS_CENTER);
	window.set_border_width(10);
	window.add(grid);

	frame.set_label("IP Info");
	frame.set_size_request(500, 250);	// Sets minimum size of the window.
	frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);

	grid.attach(frame, 0, 0, 2, 1);
	grid.attach(button_1, 0, 10, 1, 1);
	grid.attach(button_2, 1, 10, 1, 1);
	grid.set_border_width(10);

	button_1.signal_clicked().connect(sigc::ptr_fun(&on_button_1_click));
	button_2.signal_clicked().connect(sigc::ptr_fun(&on_button_2_click));

	button_1.show();
	button_2.show();
	grid.show();
	window.show_all_children();

	return app -> run(window);
}

void on_button_1_click()
{
	std::cout << "Setting Up Static IP .....\n";
	system("sudo ifconfig en10 192.168.0.10");
	system("sudo ifconfig en10 down ; sudo ifconfig en10 up");
	system("sudo ifconfig en10");

}

void on_button_2_click()
{
	std::cout << "Configuring DHCP .....\n";
	system("sudo ipconfig set en1 DHCP");
}