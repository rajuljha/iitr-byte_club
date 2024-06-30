import cloudinary.api
import os
from dotenv import load_dotenv
load_dotenv()
from flask import request
from upload import upload_img_to_db

cloudinary.config( 
    cloud_name = os.getenv('CLOUD_NAME'), 
    api_key = os.getenv('API_KEY'), 
    api_secret = os.getenv('API_SECRET') 
)

def get_img_url_from_db():
    '''
    Change function to take some sort of id as a parameter and return the img_url
    '''
    result = cloudinary.api.resource_by_asset_id("c3583c1ac389a00e3e04fb08d8a07ede")
    # result = cloudinary.api.resource(public_id)
    img_url = result['url']
    return img_url