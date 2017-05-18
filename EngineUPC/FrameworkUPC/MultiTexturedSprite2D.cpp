#include "MultiTexturedSprite2D.h"
#include "GameFramework.h"
#include "SpriteShader.h"

void MultiTexturedSprite2D::Initialize(float x, float y, const std::string path1, const std::string path2)
{
	Drawable2D::Initialize(x, y);
	ContentManager* contentManager = GameFramework::GET_FRAMEWORK()->GetContentManager();
	ShaderManager* shaderManager = GameFramework::GET_FRAMEWORK()->GetShaderManager();

	currentShader = shaderManager->LoadAndGetShader<SpriteShader>("Shaders/MultiTexturedSpriteShader");
	content1 = contentManager->LoadAndGetContent<ImageContent>(path1);
	content2 = contentManager->LoadAndGetContent<ImageContent>(path2);
	width = content1->GetWidth();
	height = content1->GetHeight();

	BindData();
}

void MultiTexturedSprite2D::Draw(float dt)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	currentShader->Use();
	GLuint wvpLocation = currentShader->GetUniformLocation("wvp");
	glm::mat4 cameraMatrix = renderCamera->GetResultMatrix();
	glm::mat4 resultMatrix = cameraMatrix*worldMatrix;

	glUniformMatrix4fv(wvpLocation, 1, GL_FALSE, &(resultMatrix[0][0]));

	GLint texLoc;
	texLoc = currentShader->GetUniformLocation("tex0");
	glUniform1i(texLoc, 0);
	texLoc = currentShader->GetUniformLocation("tex1");
	glUniform1i(texLoc, 1);

	//Tex 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, content1->GetTextureId());
	//Tex 1
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, content2->GetTextureId());

	glBindBuffer(GL_ARRAY_BUFFER, vbo_ID);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, Position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, Color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(DataSpriteVertex), (void*)offsetof(DataSpriteVertex, UV));
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
	glBindTexture(GL_TEXTURE_2D, GL_NONE);
	currentShader->Stop();
}

void MultiTexturedSprite2D::SetColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

	BindData();
}

void MultiTexturedSprite2D::BindData()
{
	DataSpriteVertex vertexData[6];

	vertexData[0].SetPosition(width, height);
	vertexData[0].SetColor(r, g, b, a);
	vertexData[0].SetUV(1.0f, 1.0f);
	vertexData[1].SetPosition(0, height);
	vertexData[1].SetColor(r, g, b, a);
	vertexData[1].SetUV(0.0f, 1.0f);
	vertexData[2].SetPosition(0, 0);
	vertexData[2].SetColor(r, g, b, a);
	vertexData[2].SetUV(0.0f, 0.0f);

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
