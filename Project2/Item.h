//#include <windows.h>
#include "GLFW\glfw3.h"
//#include <GL/gl.h>
#include <vector>
#include <fstream>
#include <string>
//#include <map>
//#include <iostream>

using namespace std;
#include "glm/glm.hpp"
#include "TexLoader.h"

//inline GLuint min(GLuint a, GLuint b) { return a < b ? a : b; }
//inline GLuint max(GLuint a, GLuint b) { return a > b ? a : b; }
//inline GLuint MinMaxed(GLuint number, GLuint bottom, GLuint top) { return min(max(number, bottom), top); }
//#define M_PI 3.1415926535
//#define M_TWO_PI 6.28318530718
//const GLuint MIN_PRECISION = 4;
//const GLuint MAX_PRECISION = 0x7ff;

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
};*/


struct Mesh
{
	vector<glm::vec3> position;
	vector<glm::vec3> normal;
	vector<glm::vec2> texCoord;
	//vector<GLuint> m_indicies;

	void Load(string filename, string texname) {


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
					tCoord.push_back(temp1);
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
		
	}
	//Draw_Primitive m_primitive = Draw_Primitive::Triangles;
	//Draw_Type m_Draw_Type = Draw_Type::Elements;
	// Очищает вершины и индексы, устанавливает тип примитива.
	//void Clear(Draw_Primitive meshType);

	// Рисует сетку примитивов, используя массивы индексов и вершин.
	void Draw() {
		if (position.size()) {

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_NORMAL_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			// Выполняем привязку vertex array и normal array
			glVertexPointer(3, GL_FLOAT, 0, position.data());
			glNormalPointer(GL_FLOAT, 0, normal.data());
			glTexCoordPointer(2, GL_FLOAT, 0, texCoord.data());

			// Выполняем внешнюю функцию.
			glDrawArrays(GL_TRIANGLES, 0, GLsizei(position.size()));

			// Выключаем режим vertex array и normal array.
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_NORMAL_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);
		}



	}
};

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
