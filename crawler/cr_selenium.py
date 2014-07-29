#!/usr/bin/python
'''
this is a simple example of how to extract information from a website
with selenium+webdriver and python
use with care

http://www.telapreta.com.br
'''

from selenium import webdriver
from time import sleep

def get_company_name(box):
    Name = box.find_elements_by_class_name('fig-title')
    return Name[0].text, Name[1].text

def get_address(box):
    Address = box.find_elements_by_class_name('fig-dates')
    return Address[0].text

firefox = webdriver.Firefox()
firefox.get(
    'http://www.paginasamarillas.com.co/busqueda/informatica-bogota'
    )

for pag in range(2, 6):
    ''' GET all box from company '''
    all_box_company = firefox.find_elements_by_class_name(
        'company-stats'
        )
    for one_box in all_box_company:
        print get_company_name(one_box)
        print get_address(one_box)
    firefox.execute_script(
        "javascript:UpdateOrderResults("+str(pag)+",'','');"
        )
    sleep(20)

firefox.close()
