#include <ros/ros.h>
#include "service_template/Nothing.h"

bool nothing_service_callback(service_template::Nothing::Request &req,
								service_template::Nothing::Response &res)
{
	if (req.service_in)
	{
		res.service_out = true;
	}
	else
	{
		res.service_out = false;
	}

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "nothing_service_server");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("nothing_service", nothing_service_callback);
	ros::spin();

	return 0;
}