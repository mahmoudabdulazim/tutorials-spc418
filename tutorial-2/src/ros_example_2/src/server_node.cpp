/*
Normal includes
*/
#include <iostream>
#include "ros/ros.h"

// Here we include the header file that defines the service, that was generated from the .srv file
#include "ros_example_2/AddTwoInts.h"

// This is the declaration of service call_back function. This procedure is the one invoked when the request is recieved 
bool add(ros_example_2::AddTwoInts::Request &req, ros_example_2::AddTwoInts::Response &res);

int main(int argc, char* argv[])
{
	ros::init(argc,argv,"example_server_node");
	ros::NodeHandle server_node_handle;

	// Here we use the ros::NodeHandle::advertiseService() method to create and return a server object
	ros::ServiceServer service_server = server_node_handle.advertiseService("add_two_ints",add);

	ROS_INFO("Service is ready \n");
	// This is to put the node in an idle listening state, to monitor the callback queue and execute any
	ros::spin();

	return 0;
}

// This is the definition of the service callback function defined earlier
bool add(ros_example_2::AddTwoInts::Request &req, ros_example_2::AddTwoInts::Response &res)
{
	ROS_INFO("Received a request \n");
	ROS_INFO("Request is to add %ld and %ld", req.a, req.b);
	res.sum = req.a + req.b;
	ROS_INFO("Response is readied, summation is: %ld \n", res.sum);
	return true;
}
