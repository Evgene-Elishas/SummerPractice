#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include "stb\stb_image.h"
#include <windows.h>
#include "GLFW\glfw3.h"
#include <fstream>

struct MyTexture {
	GLuint texID;
	GLint w, h;
	GLenum format;

	bool Load(char* filename) {
		glGenTextures(1, &texID);
		int nrComponents, is_loaded = FALSE;
		unsigned char* data = stbi_load(filename, &w, &h, &nrComponents, 0);
		if (data)
		{
			is_loaded = TRUE;
			if (nrComponents == 1) format = GL_RED;
			else if (nrComponents == 3)format = GL_RGB;
			else if (nrComponents == 4)format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, texID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);

			glBindTexture(GL_TEXTURE_2D, 0);
		}
		else {log_file << "Не удалось считать текстуру из файла: " << filename << endl; log_file.flush();}
		stbi_image_free(data);
		return is_loaded;
	}

	void Bind() {
		glBindTexture(GL_TEXTURE_2D, texID);
	}

	static void UnBind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	~MyTexture() {
		glDeleteTextures(1, &texID);
	}
};
