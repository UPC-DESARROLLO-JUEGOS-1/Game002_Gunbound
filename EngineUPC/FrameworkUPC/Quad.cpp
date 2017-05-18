#include "Quad.h"
#include "GameFramework.h"
#include "ShaderManager.h"
#include "PrimitiveShader.h"

void Quad::Initialize(float x, float y, int width, int height)
{
	Drawable2D::Initialize(x, y);
	ShaderManager* shaderManager = GameFramework::GET_FRAMEWORK()->GetShaderManager();
	currentShader = shaderManager->LoadAndGetShader<PrimitiveShader>("Shaders/PrimitiveShader");
	this->width = width;
	this->height = height;
	r = g = b = a = 255;

	BindData();
}

void Quad::Update(float dt)
{
	if (needMatrixUpdate)
	{
		glm::mat4 result(1.0f);
		glm::vec3 translate(position.x, position.y, 0.0f);
		glm::vec3 scale(scale.x, scale.y, 0.0f);
		glm::vec3 rotation(0.0f, 0.0f, 1.0f);

		glm::vec3 center(width*0.5f, height*0.5f, 0.0f);
		
		result = glm::translate(result, translate);
		result = glm::scale(result, scale);
		result = glm::translate(result, center);
		result = glm::rotate(result, rotationZ, rotation);
		result = glm::translate(result, -center);
		
		worldMatrix = result;
		needMatrixUpdate = false;
	}
}

void Quad::Draw(float dt)
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
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	currentShader->Stop();
}

void Quad::SetColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	BindData();
}

void Quad::BindData()
{
	DataPrimitiveVertex vertexData[6]; //2 triangles=1 quad
	//triangle 1
	vertexData[0].SetPosition(width, height);
	vertexData[0].SetColor(r, g, b, a);
	vertexData[1].SetPosition(0, height);
	vertexData[1].SetColor(r, g, b, a);
	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(r, g, b, a);
	//triangle 2
	vertexData[3].SetPosition(0, 0);
	vertexData[3].SetColor(r, g, b, a);
	vertexData[4].SetPosition(width, 0);
	vertexData[4].SetColor(r, g, b, a);
	vertexData[5].SetPosition(width, height);
	vertexData[5].SetColor(r, g, b, a);

	int dataSize = sizeof(vertexData);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glBufferData(GL_ARRAY_BUFFER, dataSize, vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
}
