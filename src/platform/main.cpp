#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>

int main(void)
{
	#if PRODUCTION_BUILD == 1
		SetTraceLogLevel(LOG_NONE); // no log ouput if production build is on
	#endif

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "SandBox Craft");
	SetExitKey(KEY_NULL);
	SetTargetFPS(45);

	rlImGuiSetup(true);

	//this thing here called pragma region, lets us fold all the code between it and pragma endregion, useful for organization
#pragma region imgui  
	
		
		ImGuiIO &io = ImGui::GetIO();

		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.FontGlobalScale = 2.5;
	
#pragma endregion

	if (!initGame())
	{
		return 0;
	}

	while (!WindowShouldClose() && !IsKeyDown(KEY_P))
	{
		BeginDrawing();
		ClearBackground(BLACK);
		


#pragma region imgui;
		rlImGuiBegin();
		//Docking stuff..
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
		ImGui::StyleColorsDark();

		//ImGui::StyleColorsClassic();
		//ImGui::StyleColorsLight();
#pragma endregion;

		if (!updateGame())
		{
			CloseWindow();
		}

#pragma region imgui window 1;
		ImGui::Begin("Window1"); 
		ImGui::Text("hello");
		static bool v;
		ImGui::Checkbox("Hello", &v);
		static bool a1;
		ImGui::RadioButton("Radio", &a1);

		static int a2;
		ImGui::InputInt("Type", &a2, 1, 100, 0);

		static float b1;
		ImGui::DragFloat3("Idk", &b1, 0.001, 0.0, 1.0, "%.2f", 0);

		
		if (ImGui::Button("button"))
		 {
		std::cout << "You pressed a button\n";
		}

		ImGui::Button("button2");
		static float a = 0;
		ImGui::SliderFloat("Slider", &a, 0, 1);
		ImGui::End();

#pragma endregion;
#pragma region imgui window 2;

		ImGui::Begin("Window2");
		ImGui::Text("hello");

		const ImVec2 vb = {(100.0), (200.0)};
		static float v3; // to Implement any of these in gameplay just use these 
//		                // variables already created.

		ImGui::VSliderFloat("VS", vb, &v3, 0.0, 2.0, "%.3f", 0);

		ImGui::Button("button3");
		ImGui::SameLine();
		ImGui::Button("button4");

		static float v_rad;
		ImGui::SliderAngle("Slider angle", &v_rad, 0.0, 360.0, "%.2f deg", 0);

		static float col; // if the float isnt static the changes dont show
		ImGui::ColorEdit3("Color Picker", &col, 0);

		static float col2;
		const float n = 0.0f;
		ImGui::ColorPicker4("Color picker 4", &col2, 0, &n);


		static float fraction = 0.0f; // use 0.0f instead of NULL, NULL is null pointer not a numerical value, also nullptr is better to avoid confusion.
		const ImVec2 progressVector = {(500.0f),(50.50f)};
		const char progressNull = 0.0f;
		ImGui::ProgressBar(fraction, progressVector, &progressNull);

		if (ImGui::Button("Button123"))
		{
			fraction += .001; // this number is basically getting multiplied by the fps 
		}                     // thats why += 1.0 automatically fills it up


		
		if(ImGui::CollapsingHeader("Collapsing header", ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick)) // when trying to set up flags use "|" instead of &&, 
//		                                                                                                                    // "&&" is logical AND: it checks whether both values are true and 
//																															// return a single bool, instead of the bitwise operator "|" that
//																													// combines the flag bits, 
		{

			ImGui::Text("hallo amerima"); // dont use treepop inside collapsing header, only inside TreeNode, or you'll get an error.
		}




		static char buffer[12] = ""; // this simply limits how many characters can the string hold
		ImGuiInputTextFlags flags =
    	ImGuiInputTextFlags_CharsNoBlank |        // no spaces
    	ImGuiInputTextFlags_EnterReturnsTrue |    // return true on Enter
    	ImGuiInputTextFlags_AutoSelectAll;        // select all text when focused
 
		if (ImGui::InputText("Player Name", buffer, sizeof(buffer), flags))
		{	
    	std::cout << "Confirmed name: " << buffer << "\n";
		}


		
		const ImVec2 ChildWindowSize = {(500.0f),(500.0f)};

		if (ImGui::BeginChild("Tiny Window", ChildWindowSize, true))

		{

			ImGui::Text("Random shi");

		}
		
		ImGui::EndChild();


		ImGui::End();

		rlImGuiEnd();
#pragma endregion;

		EndDrawing();


	}

	rlImGuiShutdown();

	CloseWindow();
	

	return 0;
}