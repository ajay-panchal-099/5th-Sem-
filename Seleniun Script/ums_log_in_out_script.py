from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from selenium.webdriver.support.select import Select

# Links
url = "https://ums.lpu.in/lpuums/"
username = "11801375"
password = "Sanju@123"
path = r"C:\Users\AJAY\Downloads\DRIVERS\chromedriver_win32\chromedriver.exe"  # path of web driver

# driver
driver = webdriver.Chrome(executable_path=path)
# open url
driver.get(url)
# wait in case of slow net speed
driver.implicitly_wait(5)
# finding username and password field on page
User = driver.find_element_by_name("txtU")
passW = driver.find_element_by_name("TxtpwdAutoId_8767")
# enter username
User.click()
User.send_keys(username)
User.send_keys(Keys.ENTER)
# enter password
passW = driver.find_element_by_name("TxtpwdAutoId_8767")
passW.send_keys(password)
# select the Home Page
drp = Select(driver.find_element_by_id("ddlStartWith"))
drp.select_by_value("default3.aspx")
# click on Log In button
driver.find_element_by_name("iBtnLogins").click()
# wait for 10 sec
time.sleep(10)
# Log out from the UMS
driver.find_element_by_xpath("//*[@id='header']/div[2]/div[2]/div[2]/ul/li[3]/a").click()
# close the browser
driver.close()
