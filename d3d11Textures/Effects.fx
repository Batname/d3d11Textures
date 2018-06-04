
cbuffer cbPerObject
{
	float4x4 WVP;
	bool bIsLeft;
};

Texture2D ObjTexture;
SamplerState ObjSamplerState;

struct VS_OUTPUT
{
	float4 Pos : SV_POSITION;
	float2 TexCoord : TEXCOORD;
};

VS_OUTPUT VS(float4 inPos : POSITION, float2 inTexCoord : TEXCOORD)
{
    VS_OUTPUT output;
	inPos.x /= 2.0;
	if (bIsLeft)
	{
		inPos.x -= 0.5;
		inTexCoord.x = inTexCoord.x;
	}
	else
	{
		inPos.x += 0.5;
		inTexCoord.x = inTexCoord.x;
	}


	output.Pos = mul(inPos, WVP);
    output.TexCoord = inTexCoord;

    return output;
}

float4 PS(VS_OUTPUT input) : SV_TARGET
{
	//return float4(0.1, 0.1, 0.1, 1.0);
    return ObjTexture.Sample( ObjSamplerState, input.TexCoord );
}