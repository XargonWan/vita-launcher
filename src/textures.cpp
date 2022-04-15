#include <imgui_vita2d/imgui_vita.h>
#include <vita2d.h>

#include "textures.h"
#include "config.h"
#include "gui.h"

Tex no_icon;
Tex favorite_icon;
Tex square_icon;
Tex triangle_icon;
Tex circle_icon;
Tex cross_icon;
Tex start_icon;
Tex folder_icon;
Tex selected_icon;
Tex redbar_icon;
Tex greenbar_icon;

namespace Textures {
	
	void LoadFonts()
	{
		// Build and load the texture atlas into a texture
		uint32_t* pixels = NULL;
		int width, height;
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->AddFontFromFileTTF(
					"ux0:app/SMLA00001/Ubuntu-R.ttf",
					16.0f,
					0,
					io.Fonts->GetGlyphRangesDefault());
	}

	bool LoadImageFile(const std::string filename, Tex *texture)
	{
		// Load from file
		vita2d_texture *image = vita2d_load_PNG_file(filename.c_str());
		if (image == NULL) {
			return false;
		}

		if (enable_bilinear_filter)
		{
			vita2d_texture_set_filters(image, SCE_GXM_TEXTURE_FILTER_LINEAR, SCE_GXM_TEXTURE_FILTER_LINEAR);
		}

		int image_width = vita2d_texture_get_width(image);
		int image_height = vita2d_texture_get_height(image);

		texture->id = image;
		texture->width = image_width;
		texture->height = image_height;

		return true;
	}
	
	void Init(void) {
		Textures::LoadImageFile("ux0:app/SMLA00001/noicon.png", &no_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/favorite.png", &favorite_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/square.png", &square_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/triangle.png", &triangle_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/circle.png", &circle_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/cross.png", &cross_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/start.png", &start_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/folder.png", &folder_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/selected.png", &selected_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/redbar.png", &redbar_icon);
		Textures::LoadImageFile("ux0:app/SMLA00001/greenbar.png", &greenbar_icon);
	}

	void Exit(void) {
		vita2d_free_texture(no_icon.id);
		vita2d_free_texture(favorite_icon.id);
		vita2d_free_texture(square_icon.id);
		vita2d_free_texture(triangle_icon.id);
		vita2d_free_texture(circle_icon.id);
		vita2d_free_texture(cross_icon.id);
		vita2d_free_texture(start_icon.id);
		vita2d_free_texture(folder_icon.id);
		vita2d_free_texture(selected_icon.id);
		vita2d_free_texture(redbar_icon.id);
		vita2d_free_texture(greenbar_icon.id);
	}

	void Free(Tex *texture) {
		if (texture->id != no_icon.id)
		{
			vita2d_free_texture(texture->id);
		}
	}
	
}
