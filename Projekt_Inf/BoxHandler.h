#pragma once
namespace Program
{
	namespace Helpers
	{
		ref class BoxHandler abstract sealed
		{
		public:
			static void handleError(System::String^ message);
			static bool confirmBox(System::String^ title, System::String^ text, System::Windows::Forms::MessageBoxIcon icon);
		};
	}
}

