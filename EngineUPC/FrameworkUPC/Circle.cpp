#include "Circle.h"
#include "GameFramework.h"
#include "ShaderManager.h"
#include "PrimitiveShader.h"

#include <math.h>

void Circle::Initialize(float x, float y, int radius)
{
	Drawable2D::Initialize(x, y);
	ShaderManager* shaderManager = GameFramework::GET_FRAMEWORK()->GetShaderManager();
	currentShader = shaderManager->LoadAndGetShader<PrimitiveShader>("Shaders/PrimitiveShader");
	this->radius = radius;
	angles = 30;
	r = g = b = a = 255;

	BindData();
}

void Circle::Draw(float dt)
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
	glDrawArrays(GL_TRIANGLES, 0, angles*3);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	currentShader->Stop();
}

void Circle::SetColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	BindData();
}

void Circle::BindData()
{
	DataPrimitiveVertex* vertexData=new DataPrimitiveVertex[angles*3];

	float angle = (2*M_PI) / angles;
	float currentAngle = angle;

	float auxX, auxY;

	for (int i = 0;i < angles*3;i+=3)
	{
		float cx = radius * cos(currentAngle);
		float cy= radius * sin(currentAngle);
		
		vertexData[i].SetPosition(cx, cy);
		vertexData[i].SetColor(r, g, b, a);

		currentAngle += angle;
		float cx1 = radius * cos(currentAngle);
		float cy1 = radius * sin(currentAngle);

		vertexData[i + 1].SetPosition(cx1, cy1);
		vertexData[i + 1].SetColor(r, g, b, a);
		
		vertexData[i + 2].SetPosition(0, 0);
		vertexData[i + 2].SetColor(r, g, b, a);
	}
	
	int dataSize = (sizeof(float) * 2 + sizeof(GLubyte) * 4)*(angles * 3);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, &(vertexData[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
}
