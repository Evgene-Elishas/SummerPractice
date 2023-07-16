//#include <windows.h>
//#include "GLFW\glfw3.h"
//#include <GL/gl.h>
#include <vector>
#include <fstream>
#include <string>
//#include <iostream>

using namespace std;
#include "glm/glm.hpp"
#include "TexLoader.h"

/*enum Draw_Primitive
{
	Triangles = GL_TRIANGLES,
	TriangleFan = GL_TRIANGLE_FAN,
	TriangleStrip = GL_TRIANGLE_STRIP,
	LineStrip = GL_LINE_STRIP
};
enum Draw_Type
{
	Elements,
	Arrays
};

struct Vertex
{
	glm::vec3 position;
	glm::vec2 texCoord;
	glm::vec3 normal;
};*/

struct Mesh
{
	vector<glm::vec3> position;
	vector<glm::vec3> normal;
	vector<glm::vec2> texCoord;
	//vector<GLuint> m_indicies;

	void Load(string filename) {
		vector<glm::vec3> pos;
		vector<glm::vec3> norm;
		vector<glm::vec2> tCoord;

		fstream f(filename);
		string line;
		glm::vec3 temp1;
		glm::vec2 temp2;
		GLuint v1, t1, n1, v2, t2, n2, v3, t3, n3;
		if (f) {
			while (!f.eof())
			{
				getline(f, line);
				if (line.find("vn ") == 0) {
					sscanf(line.c_str(), "vn %f %f %f", &temp1.x, &temp1.y, &temp1.z);
					norm.push_back(temp1);
				}
				else if (line.find("vt ") == 0) {
					sscanf(line.c_str(), "vt %f %f", &temp2.x, &temp2.y);
					temp2.y = 1 -temp2.y;
					tCoord.push_back(temp2);
				}
				else if (line.find("v ") == 0) {
					sscanf(line.c_str(), "v %f %f %f", &temp1.x, &temp1.y, &temp1.z);
					pos.push_back(temp1);
				}
				else if (line.find("f ") == 0) {
					sscanf(line.c_str(), "f  %u/%u/%u %u/%u/%u %u/%u/%u", &v1, &t1, &n1, &v2, &t2, &n2, &v3, &t3, &n3);
					position.push_back(pos[v1 - 1]);
					normal.push_back(norm[n1 - 1]);
					texCoord.push_back(tCoord[t1 - 1]);

					position.push_back(pos[v2 - 1]);
					normal.push_back(norm[n2 - 1]);
					texCoord.push_back(tCoord[t2 - 1]);

					position.push_back(pos[v3 - 1]);
					normal.push_back(norm[n3 - 1]);
					texCoord.push_back(tCoord[t3 - 1]);

				}
			}
		}
		else {log_file << "Не удалось считать объект из файла: " << filename << endl; log_file.flush();}
		
	}

	void Draw() { // Рисует сетку примитивов, используя массивы и вершин.
		if (position.size()) {
			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glVertexPointer(3, GL_FLOAT, 0, position.data());
			glNormalPointer(GL_FLOAT, 0, normal.data());
			glTexCoordPointer(2, GL_FLOAT, 0, texCoord.data());

			glDrawArrays(GL_TRIANGLES, 0, GLsizei(position.size()));

			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);
		}
	}
};