<?php include 'includes/db.php';
	if(isset($_POST['submit_doctor'])){
			$sel_city="SELECT * FROM city WHERE c_id='$_POST[city]'";
			$sel_spec="SELECT * FROM speciality WHERE s_id='$_POST[speciality]'";
			$run_city = mysqli_query($conn,$sel_city);
			$run_spec = mysqli_query($conn,$sel_spec);
			$rows_city=mysqli_fetch_assoc($run_city);
			$rows_spec=mysqli_fetch_assoc($run_spec);
			$ins_sql = "INSERT INTO doctors (f_name,l_name,speciality,city,fees,qualification,clinic_address,home_address,contact_no,alt_contact_no,gender,dob,email,timings,years_of_exp) VALUES ('$_POST[first_name]', '$_POST[last_name]', '$rows_spec[s_name]', '$rows_city[c_name]', '$_POST[fees]', '$_POST[qual]', '$_POST[clinic_address]', '$_POST[home_address]', '$_POST[contact_no]', '$_POST[alt_contact_no]', '$_POST[gender]', '$_POST[dob]', '$_POST[email]', '$_POST[timings]', '$_POST[yoe]')";
			$run_sql = mysqli_query($conn,$ins_sql);
		}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>MyPracto</title>
		<link rel="stylesheet" href="../bootstrap/css/bootstrap.css">
		<script src="../bootstrap/js/bootstrap.js"></script>
		<script src="../js/jquery.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div class="container">
			<article class="row">
				<section class="col-lg-8">
					<div class="page-header">
						<h2>Registration Form</h2>
						<h5>(All fields are required)</h5>
					</div>
					<form class="form-horizontal" action="registration.php" method="post" role="form">
						<div class="form-group">
							<label for="first_name" class="col-sm-3 control-label">First Name: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="first_name" placeholder="Insert your Name" id="first_name" required>
							</div>
						</div>
						<div class="form-group">
							<label for="last_name" class="col-sm-3 control-label">Last Name: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="last_name" placeholder="Insert your Name" id="last_name" required>
							</div>
						</div>
						<div class="form-group">
							<label for="email" class="col-sm-3 control-label">Email Address: </label>
							<div class="col-sm-8">
								<input type="email" class="form-control" name="email" placeholder="Email Address" id="email" required>
							</div>
						</div>
						<!---<div class="form-group">
							<label for="passsword" class="col-sm-3 control-label">Password *</label>
							<div class="col-sm-8">
								<input type="password" class="form-control" name="password" placeholder="Insert a password" id="password" required>
							</div>
						</div>
						<div class="form-group">
							<label for="con_passsword" class="col-sm-3 control-label"> Confirm Password *</label>
							<div class="col-sm-8">
								<input type="password" class="form-control" name="con_password" placeholder="Confirm password" id="con_password" required>
							</div>
						</div>--->
						<div class="form-group">
							<label for="gender" class="col-sm-3 control-label"> Gender: </label>
							<div class="col-sm-8">
								<select class="form-control" name="gender" id="gender" required>
									<option value="">Select Gender</option>
									<option value="male">Male</option>
									<option value="female">Female</option>
								</select>
							</div>
						</div>
						<div class="form-group">
							<label for="contact_no" class="col-sm-3 control-label"> Contact No: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="contact_no" id="contact_no" placeholder="Insert Your Contact No." id="contact_no" required>
							</div>
						</div>
						<div class="form-group">
							<label for="alt_contact_no" class="col-sm-3 control-label"> Alternate Contact No: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="alt_contact_no" id="alt_contact_no" placeholder="Insert Your Alternate Contact No." id="alt_contact_no" required>
							</div>
						</div>
						<div class="form-group">
							<label for="designation" class="col-sm-3 control-label"> Speciality: </label>
							<div class="col-sm-8">
								<select id="speciality" name="speciality" class="form-control" required>
									<option value="" selected>Select Speciality</option>
									<?php
										$sel_sql = "SELECT * FROM speciality";
										$run_sql = mysqli_query($conn,$sel_sql);
										while($rows = mysqli_fetch_assoc($run_sql)){
											echo '<option value="'.$rows['s_id'].'">'.ucfirst($rows['s_name']).'</option>';
										}
									?>
								</select>
							</div>
						</div>
						<div class="form-group">
							<label for="city" class="col-sm-3 control-label"> City: </label>
							<div class="col-sm-8">
							<select id="city" name="city" class="form-control" required>
								<option value="" selected>Select City</option>
								<?php
									$sel_sql = "SELECT * FROM city";
									$run_sql = mysqli_query($conn,$sel_sql);
									while($rows = mysqli_fetch_assoc($run_sql)){
										echo '<option value="'.$rows['c_id'].'">'.ucfirst($rows['c_name']).'</option>';
									}
								?>
							</select>
							</div>
						</div>
						<div class="form-group">
							<label for="home_address" class="col-sm-3 control-label"> Home Address: </label>
							<div class="col-sm-8">
								<textarea class="form-control" name="home_address" id="home_address" rows="2" required></textarea>
							</div>
						</div>
						<div class="form-group">
							<label for="clinic_address" class="col-sm-3 control-label"> Clinic Address: </label>
							<div class="col-sm-8">
								<textarea class="form-control" name="clinic_address" id="clinic_address" rows="2"required></textarea>
							</div>
						</div>
						<div class="form-group">
							<label for="timings" class="col-sm-3 control-label"> Clinic Timings:(hh:mm-hh:mm)</label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="timings" placeholder="Enter Clinic Timings(as per 24hr clock)" id="timings" required>
							</div>
						</div>
						<div class="form-group">
							<label for="fees" class="col-sm-3 control-label"> Consultation Fees(Rs.): </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="fees" placeholder="Enter your fees" id="fees" required>
							</div>
						</div>
						<div class="form-group">
							<label for="qual" class="col-sm-3 control-label"> Qualification:</label>
							<div class="col-sm-8">
								<textarea class="form-control" name="qual" id="qual" rows="2"required></textarea>
							</div>
						</div>
						<div class="form-group">
							<label for="dob" class="col-sm-3 control-label"> Date Of Birth: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="dob" placeholder="Enter your Date Of Birth(dd-mm-yyyy)" id="dob" required>
							</div>
						</div>
						<div class="form-group">
							<label for="yoe" class="col-sm-3 control-label"> Years Of Experience: </label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="yoe" placeholder="Enter years of experience" id="yoe" required>
							</div>
						</div>
						<div class="form-group">
							<label class="col-sm-3 control-label"></label>
							<div class="col-sm-8">
								<input type="submit" value="Register yourself as doctor" name="submit_doctor" class="btn btn-block btn-danger" id="submit_doctor">
							</div>
						</div>
					</form>
					
				</section>
				<?php include 'includes/sidebar.php';?>
			</article>
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>