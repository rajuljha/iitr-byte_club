import cloudinary.uploader
import os
from dotenv import load_dotenv
load_dotenv()
from flask import request

cloudinary.config( 
    cloud_name = os.getenv('CLOUD_NAME'), 
    api_key = os.getenv('API_KEY'), 
    api_secret = os.getenv('API_SECRET') 
)

def upload_img_to_db():
    '''
    Change function to upload the image retrieved from the user through html form.
    **public_id** field should be unique in our database. What should we keep it?
    We can take url of file to be uploaded from user also.
    '''
    file = request.files['file']
    public_id = request.form['public_id']
    cloudinary.uploader.upload(file,
                            public_id = public_id)
    return public_id
