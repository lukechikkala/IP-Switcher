#include <gtkmm.h>
#include <iostream>
#include <string.h>

void on_button_1_click();
void on_button_2_click();

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "lukeroyal.com");

	Gtk::Window window;
	Gtk::Button button_1("Static");
	Gtk::Button button_2("DHCP");
	Gtk::Grid grid;
	Gtk::Frame frame;
	Gtk::Box box;
	Gtk::Label label;
	label.set_label("Current IP Information will appear here");

	window.set_title("IP Switcher");
	window.set_default_size(500,250);
	window.set_position(Gtk::WIN_POS_CENTER);
	window.set_border_width(10);
	window.add(grid);

	frame.set_label("IP Info");
	frame.set_label_align(0.02, 0.5);
	frame.set_size_request(500, 250);	// Sets minimum size of the window.
	label.set_halign(Gtk::ALIGN_START);
	label.set_valign(Gtk::ALIGN_START);
	label.set_margin_start(30);
	label.set_margin_top(20);
	frame.add(label);

/*
	The Frame Shadow Type does not work on macOS, there might be better luck with Windows / Linux.
	Types of Frame Shadow:
		Gtk:SHADOW_NONE
		Gtk:SHADOW_IN
		Gtk:SHADOW_OUT
		Gtk:SHADOW_ETCHED_IN (default)
		Gtk:SHADOW_ETCHED_OUT
	Syntax:
		frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);
*/
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
	std::string msg = "Static";
	Gtk::Label label;
	label.set_text(msg);

//	Gtk::Label label("msg", true);
//	label.set_label("Static");

/*	##########	macOS Commands	##########
	----------------------------------------------------------------------------------------------------
	system("sudo ifconfig en10 192.168.0.10");
	system("sudo ifconfig en10 down ; sudo ifconfig en10 up");
	system("sudo ifconfig en10");
	----------------------------------------------------------------------------------------------------
*/

/*	##########	win Commands	##########
	----------------------------------------------------------------------------------------------------
	system("netsh int ipv4 set address name=\"Ethernet 2\" static 192.168.1.77 255.255.255.0");
	system("netsh int ipv4 add address \"Ethernet 2\" 2.168.1.77 255.0.0.0");
	system("netsh int ipv4 add address \"Ethernet 2\" 10.168.100.77 255.255.255.0");
	system("netsh int ipv4 add address \"Ethernet 2\" 192.168.3.77 255.255.255.0");
	system("netsh int ipv4 add address \"Ethernet 2\" 192.168.100.77 255.255.255.0");
	system("cls");
	system("timeout 5");
	system("ipconfig");
	----------------------------------------------------------------------------------------------------
*/
}

void on_button_2_click()
{
	std::cout << "Configuring DHCP .........\n";

/*	##########	macOS Commands	##########
	----------------------------------------------------------------------------------------------------
	system("sudo ipconfig set en1 DHCP");
	----------------------------------------------------------------------------------------------------
*/

/*	##########	win Commands	##########
	----------------------------------------------------------------------------------------------------
	system("netsh int ipv4 set address "Ethernet 2" dhcp");
	system("cls");
	system("timeout 5");
	system("ipconfig");
	----------------------------------------------------------------------------------------------------
*/
}

/*

Wishes:
	Add progress bar
	https://developer.gnome.org/gtkmm-tutorial/stable/sec-multithread-example.html.en

*/

/*
Current Status:
	Currently unable to change the label inside the frame to display the text.

	Ideally, default text should display the current IP information:

	#### IP Info #########################################
	##													##
	##	IP address	: 192.168.0.77		255.255.255.0	##
	##													##
	##													##
	##													##
	##													##
	##													##
	######################################################

	If the user presses "DHCP", the frame should contain text like:

	#### IP Info #########################################
	##													##
	##	Configuring DHCP .....							##
	##													##
	##	╭───────────────────────────╮					##
	##	│░░░░░░░░░░░				│	42%				##
	##	╰───────────────────────────╯					##
	##													##
	######################################################

	#### IP Info #########################################
	##													##
	##	IP address	: 169.254.32.56		255.255.0.0		##
	##													##
	##													##
	##													##
	##													##
	##													##
	######################################################

	If the user presses "Static", the frame should contain text like:

	#### IP Info #########################################
	##													##
	##	Setting up Static IP Addresses					##
	##													##
	##	╭───────────────────────────╮					##
	##	│░░░░░░░░░░░				│	42%				##
	##	╰───────────────────────────╯					##
	##													##
	######################################################

	#### IP Info #########################################
	##													##
	##	IP address	: 192.168.0.77		255.255.255.0	##
	##	IP address	: 192.168.1.77		255.255.255.0	##
	##	IP address	: 192.168.3.77		255.255.255.0	##
	##	IP address	: 192.168.100.77	255.255.255.0	##
	##	IP address	: 2.168.0.77		255.255.255.0	##
	##													##
	######################################################

*/
