#include "Sprite.h"
#include "GameFramework.h"
#include "SpriteShader.h"

void Sprite::SetColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	BindData();
}

void Sprite::Initialize(float x, float y, const std::string path)
{
	Drawable2D::Initialize(x, y);
	GameFramework* framework = GameFramework::GET_FRAMEWORK();
	ContentManager* contentManager = framework->GetContentManager();
	ShaderManager* shaderManager = framework->GetShaderManager();

	currentShader = shaderManager->LoadAndGetShader<SpriteShader>("Shaders/SpriteShader");
	content = contentManager->LoadAndGetContent<ImageContent>(path);
	width = content->GetWidth();
	height = content->GetHeight();
	r = g = b = a = 255;

	BindData();
}

void Sprite::Update(float dt)
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

void Sprite::Draw(float dt)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	currentShader->Use();
	GLuint wvpLocation = currentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = renderCamera->GetResultMatrix();
	glm::mat4 resultMatrix = cameraMatrix*worldMatrix;

	glUniformMatrix4fv(wvpLocation, 1, GL_FALSE, &(resultMatrix[0][0]));

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, content->GetTextureId());
	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, Color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, UV));
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	currentShader->Stop();
}

void Sprite::BindData()
{
	DataSpriteVertex vertexData[6]; //2 triangles=1 quad
									//triangle 1
	vertexData[0].SetPosition(width, height);
	vertexData[0].SetColor(r, g, b, a);
	vertexData[0].SetUV(1.0f, 1.0f);
	vertexData[1].SetPosition(0, height);
	vertexData[1].SetColor(r, g, b, a);
	vertexData[1].SetUV(0.0f, 1.0f);
	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(r, g, b, a);
	vertexData[2].SetUV(0.0f, 0.0f);
	//triangle 2
	vertexData[3].SetPosition(0, 0);
	vertexData[3].SetColor(r, g, b, a);
	vertexData[3].SetUV(0.0f, 0.0f);
	vertexData[4].SetPosition(width, 0);
	vertexData[4].SetColor(r, g, b, a);
	vertexData[4].SetUV(1.0f, 0.0f);
	vertexData[5].SetPosition(width, height);
	vertexData[5].SetColor(r, g, b, a);
	vertexData[5].SetUV(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
}
