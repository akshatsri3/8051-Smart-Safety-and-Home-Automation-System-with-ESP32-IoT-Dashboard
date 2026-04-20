import streamlit as st
import time

st.set_page_config(page_title="Fire Detection", layout="centered")

st.title("🔥 Fire Detection Dashboard")

status_placeholder = st.empty()
control_placeholder = st.empty()

# store start time once
if "start_time" not in st.session_state:
    st.session_state.start_time = time.time()

# appliance state
if "appliances_on" not in st.session_state:
    st.session_state.appliances_on = True

elapsed = time.time() - st.session_state.start_time

# timing
FIRE_START = 10
FIRE_END = 20

# logic
if elapsed < FIRE_START:
    status_placeholder.success("✅ All Safe at Home")
    control_placeholder.empty()

elif FIRE_START <= elapsed < FIRE_END:
    status_placeholder.error("🔥 FLAME DETECTED AT HOME!")

    # show button only during fire
    if st.session_state.appliances_on:
        if control_placeholder.button("🚨 Close All Appliances"):
            st.session_state.appliances_on = False

    if not st.session_state.appliances_on:
        control_placeholder.warning("⚡ Appliances Turned OFF")

else:
    status_placeholder.success("✅ All Safe at Home")
    control_placeholder.empty()

# auto refresh
time.sleep(1)
st.rerun()