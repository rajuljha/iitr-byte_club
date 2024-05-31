# Copyright 2024 Tayyab Ilyas and Rajul Jha
from django.db import models
from users.models import User
# Create your models here.
class Chat(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    message = models.TextField()
    response = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'{self.user.username}: {self.message}'
    
# European Union Public License 1.1	EUPL-1.1
# GNU Affero General Public License v3.0	AGPL-3.0
# GNU General Public License family	GPL
# GNU General Public License v2.0