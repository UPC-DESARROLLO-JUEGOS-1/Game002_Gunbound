#include "Ellipse.h"
#include "GameFramework.h"
#include "ShaderManager.h"
#include "PrimitiveShader.h"

#define TWOPI M_PI*2

void Ellipse::Initialize(float x, float y, float radius, int vertexCount)
{
	Drawable2D::Initialize(x, y);
	this->radius = radius;
	this->vertexCount = vertexCount;
	r = g = b = a = 255;
	ibo_ID = 0;

	ShaderManager* shaderManager = GameFramework::GET_FRAMEWORK()->GetShaderManager();
	currentShader = shaderManager->LoadAndGetShader<PrimitiveShader>("Shaders/PrimitiveShader");

	BindData();
	BindIndices();
}

void Ellipse::Draw(float dt)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	currentShader->Use();

	GLuint wvpLocation = currentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = renderCamera->GetResultMatrix();
	glm::mat4 resultMatrix = cameraMatrix*worldMatrix;

	glUniformMatrix4fv(wvpLocation, 1, GL_FALSE, &(resultMatrix[0][0]));

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(DataPrimitiveVertex), (void*)offsetof(DataPrimitiveVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(DataPrimitiveVertex), (void*)offsetof(DataPrimitiveVertex, Color));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_ID);
	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, (void*)0);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_NONE);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	currentShader->Stop();
}

void Ellipse::BindData()
{
	int arraysize = vertexCount + 1;
	float slicedAngle = TWOPI / (float)vertexCount;

	DataPrimitiveVertex* vertexData=new DataPrimitiveVertex[arraysize];

	vertexData[0].SetPosition(position.x, position.y);
	vertexData[0].SetColor(r, g, b, a);

	for (int i = 0;i < arraysize;i++)
	{
		float auxX = position.x + radius*cosf(slicedAngle*i);
		float auxY = position.y + radius*sinf(slicedAngle*i);

		vertexData[i].SetPosition(auxX, auxY);
		vertexData[i].SetColor(r, g, b, a);
	}

	int dataSize = (sizeof(float) * 2 + sizeof(GLubyte) * 4)*arraysize;

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, &(vertexData[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
}

void Ellipse::BindIndices()
{
	if (ibo_ID == 0)
	{
		glGenBuffers(1, &ibo_ID);
		int indicesCounter = 0;
		int indicesArraySize = vertexCount * 3;
		unsigned int* indicesData = new unsigned int[indicesArraySize];

		for (int i = 0;i < indicesArraySize;i += 3)
		{
			indicesData[i] = 0;
			indicesData[i + 1] = indicesCounter + 1;
			indicesData[i + 2] = indicesCounter + 2;
			indicesCounter++;
		}

		indicesData[indicesArraySize - 1] = 1;
		indicesCount = indicesArraySize;

		int indexDataSize = sizeof(int)*indicesArraySize;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexDataSize, &(indicesData[0]), GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_NONE);
	}
}
