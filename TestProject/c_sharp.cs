using Godot;
using System;

public partial class c_sharp : Node2D
{
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		ExampleRefCounted example_ref_coutned = new ExampleRefCounted();
		Callable example_callable = example_ref_coutned.GetExmapleCallable();
		example_callable.Call();
	}
}
