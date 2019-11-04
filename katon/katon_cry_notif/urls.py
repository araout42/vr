from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('connection',  views.connection, name='connection'),
    path('register', views.register, name='register'),
    path('settings', views.settings, name='settings')
]
