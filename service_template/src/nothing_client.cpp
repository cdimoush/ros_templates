#include <ros/ros.h>
#include "service_template/Nothing.h"

class NothingClient
{
public:
	NothingClient();

private:
	ros::NodeHandle nh_;
	service_template::Nothing nothing_srv_;
};

NothingClient::NothingClient()
{

	nothing_srv_.request.service_in = true;
	ros::ServiceClient client = nh_.serviceClient<service_template::Nothing>("nothing_service");
	if (client.call(nothing_srv_))
	{
		ROS_INFO("The nothing service did nothing");
	}
	else
	{
		ROS_ERROR("The nothing service did not do nothing");
	}
}

int main (int argc, char **argv)
{
	ros::init(argc, argv, "nothing_service_client");
	NothingClient sc;
	return 0;
}