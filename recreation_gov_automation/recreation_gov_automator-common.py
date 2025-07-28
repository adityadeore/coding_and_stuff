# install selenium from pip3 install selenium
# press enter at the right time when the spots open up

from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
import time
import sys

# Specify the path to your GeckoDriver executable
# If geckodriver is in your PATH, you might not need this line or can simplify
geckodriver_path = 'C:\\Users\\adeore\\OneDrive - Arlo Technologies, Inc\\Personal\\recreation_gov_automation\\geckodriver.exe' # e.g., 'C:/Drivers/geckodriver.exe' or '/usr/local/bin/geckodriver'

# Set up Firefox options (optional)
firefox_options = Options()
firefox_options.binary_location = r'C:\Program Files\Mozilla Firefox\firefox.exe'
# firefox_options.add_argument("--headless") # Run Firefox in headless mode (without a visible GUI)

# Set up the service for GeckoDriver
service = Service(executable_path=geckodriver_path)

# Initialize the Firefox WebDriver
driver = webdriver.Firefox(service=service, options=firefox_options)

try:
    # Open the webpage
    driver.get("https://www.recreation.gov/permits/445859/registration/detailed-availability?date=2025-07-25&type=overnight-permit") # Replace with your target URL
    driver.maximize_window()
    print(f"Maximized Chrome window size: {driver.get_window_size()}")
    # Wait for the page to load (you might need more sophisticated waits for dynamic content)
    time.sleep(2)

    # --- Locate and click elements ---
    try:
        login_by_id = driver.find_element(By.ID, "ga-global-nav-log-in-link")
        login_by_id.click()
    except Exception as e:
        print(f"Could not find or click login by ID: {e}")

    try:
        email  = driver.find_element(By.ID, "email")
        email.send_keys("aditya.deore@gmail.com")
    except Exception as e:
        print(f"Could not find email: {e}")
    
    try:
        password = driver.find_element(By.ID, "rec-acct-sign-in-password")
        password.send_keys("2Jeopardy!")
    except Exception as e:
        print(f"Could not find password: {e}")
    # Example 1: Click a button by its ID
    try:
        login_css = ".sarsa-button-lg"
        login_button = driver.find_element(By.CSS_SELECTOR, login_css)
        login_button.click()
    except Exception as e:
        print(f"Could not click login button by CSS: {e}")
    time.sleep(2)
    try:
        button_by_id = driver.find_element(By.ID, "guest-counter")
        button_by_id.click()
        print("Clicked button by ID!")
        #time.sleep(1) # Wait for action to complete
    except Exception as e:
        print(f"Could not find or click button by ID: {e}")

    # Example 2: Click a button by its CSS selector
    try:
        add_people_button = driver.find_element(By.CSS_SELECTOR, 'button[aria-label="Add Peoples"]')
#        link_by_text = driver.find_element(By.LINK_TEXT, "Learn more")
        add_people_button.click()
        print("Clicked button by aria label! - 1 person")
        add_people_button.click()
        print("clicked buttin by aria label - 2 persons")
        #time.sleep(1)
    except Exception as e:
        print(f"Could not click button: {e}")
        # Go back to the previous page if you navigated away
        driver.back()
        time.sleep(1)
    #wait to load the grid
    campsite = input("Enter the campsite (rafferty/sunrise/cathedral): ")
    if(campsite == 'rafferty'):
        css_selector = ".rec-grid-row:nth-child(41) > .rec-grid-grid-cell:nth-child(12) .sarsa-button"
        driver.execute_script("window.scrollBy(0, 1421);")
    elif(campsite == 'sunrise'):
        css_selector = ".rec-grid-row:nth-child(46) > .rec-grid-grid-cell:nth-child(12) .sarsa-button"
        driver.execute_script("window.scrollBy(0, 1500);")
    elif(campsite == 'cathedral'):
        css_selector = ".rec-grid-row:nth-child(8) > .rec-grid-grid-cell:nth-child(12) .sarsa-button"
    else:
        print("Unsupported campsite")
        driver.quit()
        sys.exit(1)
    epoch_time = input("Enter the epoch time at which you want to book : ")    
    while(time.time() < epoch_time ):
        time.sleep(1)
    try:        
        hover_element = WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, css_selector))) # Example for selenium.dev site
        actions = ActionChains(driver)
        actions.move_to_element(hover_element).perform()
        element1  = WebDriverWait(driver, 20).until(EC.element_to_be_clickable((By.CSS_SELECTOR, css_selector)))
        print(f"Found item")
        element1.click()
        print("element1 clicked")
    except Exception as e:
        print(f"Could not find grid {e}")
    try:
        css_selector = ".sarsa-button-primary:nth-child(3)"
        hover_element = WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, css_selector))) # Example for selenium.dev site
        actions = ActionChains(driver)
        actions.move_to_element(hover_element).perform()
        element1  = WebDriverWait(driver, 20).until(EC.element_to_be_clickable((By.CSS_SELECTOR, css_selector)))
        print(f"Found Book")
        element1.click()
        print("Book clicked")
    except Exception as e:
        print(f"Could not find or click button by ID: {e}")

    time.sleep(20) 
except Exception as e:
    print(f"Error occured {e}")
finally:
    # Close the browser
    driver.quit()
