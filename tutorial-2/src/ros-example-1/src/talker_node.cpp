// First we include the ros.h header file necessary for ros API usage
#include "ros/ros.h"
#include <iostream>

// Here we include the header file String.h where the message type std_msgs::String is defined in order to use it in our file
#include "std_msgs/String.h"

int main(int argc, char* argv[])
{
	// ROS initialization procedure, this mainly registers the node with the master under the given name ("talker_node")
	ros::init(argc, argv, "talker_node");

	//Node handle which is used to create publishers, subscribers and other communication types
	ros::NodeHandle talker_node_handle;

	// Using the advertise method from NodeHandle methods (check the API for others) to create and return a publisher object used to
	// used to publish messages to a given topic (here it is chatter_topic) ..
	// Notice the usage of the function where we declared the type of the message that will be published on the topic between angle brackes <>
	// Check the documentation of the function in the roscpp library documentation for further details
	// the first argument of the function is the name of the topic to publish and the second argument is the queue size
	ros::Publisher talker_node_publisher = talker_node_handle.advertise<std_msgs::String>("chatter_topic",10);

	// This loop rate is used to manage rate in the ROS network. the first argument is the desired rate in Hz
	// The Rate object works by calculating the elapsed time in the computations since the last call to the constructor or the Rate::sleep()
	// function and sleeps the rest of the remaining time if any to ensure a constant loop_rate regardless of the simplicity of the
	// computations inside the main loop 
	ros::Rate loop_rate(20);

	// ros::ok() checks whether the kill sequence has been issued or not (Ctrl + C) and returns 1 as long as the sequence has not been issued
	while(ros::ok())
	{
		// Here we create an instance of the message type that we are going to send over the topic
		std_msgs::String msg;

		// The message is actually a data structure containing a single field called "data" and is of type string
		//  Here, we set that field to the desired message by simple assignment
		msg.data  = "Hello there!";

		// After creating and readying our message, we publish it using the method ros::Publisher:publish() from the Publisher class
		talker_node_publisher.publish(msg);

		// ROS is based on callbacks, so checking callbacks regularly is mandatory to provide the inter-process communication
		// ros::spinOnce() checks the callback flags if there are any callbacks that the ROS runtime system should respond to.
		ros::spinOnce();

		// check the comment on ros::Rate
		loop_rate.sleep();
	}
	return 0;
}
