<?php session_start();
	include 'includes/db.php';
	if(isset($_SESSION['user']) && isset($_SESSION['password']) == true){
		$sel_sql = "SELECT * FROM admins WHERE email = '$_SESSION[user]' AND password = '$_SESSION[password]'";
		if($run_sql = mysqli_query($conn, $sel_sql)){
			while($rows = mysqli_fetch_assoc($run_sql)){
				$name = $rows['f_name'].' '.$rows['l_name'];
				$contact_no = $rows['contact_no'];
				$email= $rows['email'];
				
				if(mysqli_num_rows($run_sql) == 1 ){
					
				} else{
					header('Location:../index.php');
				}
			}
		}
	} else {
		header('Location:../index.php');
	}
	//// Counting Doctors
	$sql = "SELECT * FROM doctors";
	$run = mysqli_query($conn,$sql);
	$total_doctors = mysqli_num_rows($run);
	
	/// Counting Cities
	
	$sql = "SELECT * FROM city";
	$run = mysqli_query($conn,$sql);
	$total_cities = mysqli_num_rows($run);
	
	///Counting Departments
	$sql = "SELECT * FROM speciality";
	$run = mysqli_query($conn,$sql);
	$total_departments = mysqli_num_rows($run);
	
	///Counting Comments
	$sql = "SELECT * FROM comments";
	$run = mysqli_query($conn,$sql);
	$total_comments = mysqli_num_rows($run);
	
	///Counting Bugs
	$sql = "SELECT * FROM bugs";
	$run = mysqli_query($conn,$sql);
	$total_bugs = mysqli_num_rows($run);
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin Panel</title>
		<link rel="stylesheet" href="../../bootstrap/css/bootstrap.css">
		<script src="../../js/jquery.js"></script>
		<script src="../../bootstrap/js/bootstrap.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div style="width:50px;height:50px;"></div>
		<div align="right" class="panel-body" style="color:brown;">
			<?php echo 'Hello, '.$_SESSION['user'];?>
		</div>
		<?php include 'includes/sidebar.php';?>
		<div class="col-lg-10">
		<div style="width:50px;height:50px;"></div>
			<div class="col-md-2">
				
				<div class="panel panel-danger">
					<div class="panel-heading">
						<div class="row">
							<div class="col-xs-3"><i class="glyphicon glyphicon-user" style="font-size:4.5em"></i></div>
							<div class="col-xs-9 text-right">
								<div style="font-size:2.5em"><?php echo $total_doctors; ?></div>
								<div>Doctors</div>
							</div>
						</div>
					</div>
					<a href="view_doctors.php">
						<div class="panel-footer">
							<div class="pull-left">View Doctors</div>
							<div class="pull-right"><i class="glyphicon glyphicon-circle-arrow-right"></i></div>
							<div class="clearfix"></div>
						</div>
					</a>
				</div>
			</div>
			
			<div class="col-md-2">
				<div class="panel panel-success">
					<div class="panel-heading">
						<div class="row">
							<div class="col-xs-3"><i class="glyphicon glyphicon-th-list" style="font-size:4.5em"></i></div>
							<div class="col-xs-9 text-right">
								<div style="font-size:2.5em"><?php echo $total_departments; ?></div>
								<div>Departments</div>
							</div>
						</div>
					</div>
					<a href="view_departments.php">
						<div class="panel-footer">
							<div class="pull-left">View Departments</div>
							<div class="pull-right"><i class="glyphicon glyphicon-circle-arrow-right"></i></div>
							<div class="clearfix"></div>
						</div>
					</a>
				</div>
			</div>
			
			<div class="col-md-2">
				<div class="panel panel-warning">
					<div class="panel-heading">
						<div class="row">
							<div class="col-xs-3"><i class="glyphicon glyphicon-road" style="font-size:4.5em"></i></div>
							<div class="col-xs-9 text-right">
								<div style="font-size:2.5em"><?php echo $total_cities; ?></div>
								<div>Cities</div>
							</div>
						</div>
					</div>
					<a href="view_cities.php">
						<div class="panel-footer">
							<div class="pull-left">View Cities</div>
							<div class="pull-right"><i class="glyphicon glyphicon-circle-arrow-right"></i></div>
							<div class="clearfix"></div>
						</div>
					</a>
				</div>
			</div>
			
			<div class="col-md-2">
				<div class="panel panel-info">
					<div class="panel-heading">
						<div class="row">
							<div class="col-xs-3"><i class="glyphicon glyphicon-comment" style="font-size:4.5em"></i></div>
							<div class="col-xs-9 text-right">
								<div style="font-size:2.5em"><?php echo $total_comments;?></div>
								<div>Comments</div>
							</div>
						</div>
					</div>
					<a href="view_comments.php">
						<div class="panel-footer">
							<div class="pull-left">View Comments</div>
							<div class="pull-right"><i class="glyphicon glyphicon-circle-arrow-right"></i></div>
							<div class="clearfix"></div>
						</div>
					</a>
				</div>
			</div>
			
			<div class="col-md-2">
				<div class="panel panel-info">
					<div class="panel-heading">
						<div class="row">
							<div class="col-xs-3"><i class="glyphicon glyphicon-comment" style="font-size:4.5em"></i></div>
							<div class="col-xs-9 text-right">
								<div style="font-size:2.5em"><?php echo $total_bugs;?></div>
								<div>Bugs</div>
							</div>
						</div>
					</div>
					<a href="view_bugs.php">
						<div class="panel-footer">
							<div class="pull-left">View Bugs</div>
							<div class="pull-right"><i class="glyphicon glyphicon-circle-arrow-right"></i></div>
							<div class="clearfix"></div>
						</div>
					</a>
				</div>
			</div>
			<div class="clearfix"></div>
			
			<!------ Top Blocks Ends----->
			<!----- Profile Area ------>
			<div class="col-lg-10">
				<div class="panel-info">
				<div class="panel-heading">
					<h4><?php echo $name; ?></h4>
				</div>
				<!--<div class="col-md8">
					<img src="../images/model.jpg" width="30%" class="img-circle">
				</div>-->
					<div class="panel-body">
						<table class="table table-condensed">
							<tbody>
								<tr>
									<th>Email:</th>
									<td><?php echo $_SESSION['user']; ?></td>
								</tr>
								<tr>
									<th>Contact:</th>
									<td><?php echo $contact_no; ?></td>
								</tr>
							</tbody>
						</table>
					</div>
				</div>
				</div>
			</div>
			</div>
			<div class="clearfix"></div>
		</div>
		<footer></footer>
	</body>
</html>