/**
 * ofxRGBDMeshBuilder
 *
 * Utility to build stitched ofMesh out of a depth image
 * Creates texture coords using the calibration image supplied.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDepthHoleFiller.h"

using namespace ofxCv;

class ofxRGBDMeshBuilder {
  public:
    ofxRGBDMeshBuilder();
    ~ofxRGBDMeshBuilder();    
    
    bool setup(string calibrationDirectory);
	bool setDepthOnly();
	
	void setTexture(ofBaseHasTexture& texture);
	void setDepthPixels(ofShortPixels& pixels);

	void update();
    void update(ofShortPixels& depthImage);
	
    void draw();
    void draw(ofBaseHasTexture& texture);

	ofVec3f worldPosition;
	ofVec3f worldRotation;
	ofVec3f pivot;
	
	void setPivotToMeshCenter();
	
    void setSimplification(int simplifyLevel);
    int getSimplification();
    
	ofxDepthHoleFiller& getHoleFiller();
	
    void setXYShift(ofVec2f shift);
    ofVec2f shift;
	ofVec2f scale;
	ofVec2f angleFov;
    ofMesh& getMesh();
    
    float farClip;
	float nearClip;
    float edgeSnip;
    
	bool mirror;
	
    bool addColors;
    bool undistortDepthImage;
    bool calculateTextureCoordinates;
    bool normalizeTextureCoordinates;
    
    void setTextureScaleForImage(ofBaseHasTexture& texture);
	Calibration depthCalibration, rgbCalibration;
    ofVec2f textureScale;
    ofVec3f getWorldPoint(float x, float y, unsigned short z);
    ofVec3f getWorldPoint(float x, float y, ofShortPixels& pixels);


  private:
    ofMesh mesh;
	
//	Calibration depthCalibration, rgbCalibration;
    Mat rotationDepthToRGB, translationDepthToRGB;
    
	ofBaseHasTexture* currentTexture;
	ofShortPixels* currentDepthPixels;
	
    Point2d principalPoint;
    cv::Size imageSize;
	
	void setupDrawMatrices();
	
	ofVec2f fov;
    int simplify;
    bool hasTriangles;
    bool calibrationSetup;
    bool depthOnly;
	
	ofxDepthHoleFiller holeFiller;
    void generateTextureCoordinates();  
    vector<ofIndexType> baseIndeces;
    
};

