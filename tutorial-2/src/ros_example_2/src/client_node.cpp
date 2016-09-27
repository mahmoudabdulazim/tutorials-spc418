#include <iostream>
#include "ros/ros.h"
#include "ros_example_2/AddTwoInts.h"
#include <string>
int main (int argc, char* argv[])
{
//	Here we check the number of arguments given to the node. If it is not equal to 3 , that means more or less than 2 arguments have been passed into the node which means an invalid input
	if (argc!=3)
	{
		ROS_INFO("invalid input, please input two numbers to be summed \n");
		ROS_INFO(" %s" , argv[0]);
	}

	ros::init(argc, argv,"client_node");
	ros::NodeHandle client_node_handle;

	ros::ServiceClient service_client = client_node_handle.serviceClient<ros_example_2::AddTwoInts>("add_two_ints");
	ros_example_2::AddTwoInts example_service;

	example_service.request.a = atoll(argv[1]);
	example_service.request.b = atoll(argv[2]);

	bool service_performed = service_client.call(example_service);

	if (service_performed)
	{
		ROS_INFO("Service is performed seamelessly, response is: %ld \n", example_service.response.sum);
	}
	else
	{
		ROS_ERROR("Service call failed, make sure the service is published \n");
		return 1;
	}

	return 0;
}
