#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"

using std::cout;
using std::endl;

// here we declare the callback function we will be using for the subcriber object
void subscriber_callback(const std_msgs::String::ConstPtr& msg);

int main(int argc, char* argv[])
{
	// ROS initialization, check the comments in the talker_node.cpp file
	ros::init(argc,argv,"listener_node");
	// NodeHandle , check the comments in the talker_node.cpp file
	ros::NodeHandle listener_node_handle;

	// Here we use the method ros::NodeHandle::subscribe() from the NodeHandle class to create and return a subscriber object that 
	// that subscribes to the "chatter_topic" and uses the function "subscriber_callback" as its callback function
	// the function "subscriber_callback" here is invoked whenever a message is detected by the subscriber on the topic "chatter_topic"
	// and the number in the second argument here is the buffer_size to fill before starting to remove messages in case of overflow
	ros::Subscriber listener_subscriber = listener_node_handle.subscribe("chatter_topic",10,subscriber_callback);

	// ros::spin here is used to put the "main" procedure in an idle state such that it doesn't quit. However, whenever, the subscriber object 
	// detects a message, it will initiate the callback procedure "subscriber_callback"
	ros::spin();
	return 0;
}

// Definition of the callback function
void subscriber_callback(const std_msgs::String::ConstPtr& msg)
{
	cout << "I recieved the following msg: " << msg->data << endl;
}
